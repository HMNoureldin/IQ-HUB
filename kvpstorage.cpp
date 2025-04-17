#include <iostream>
#include <csignal>
#include <atomic>
#include <thread>
#include <mutex>
#include <cerrno>
#include <unistd.h>
#include <cstring>
#include <sys/stat.h>
#include <sys/types.h>
#include <condition_variable>
#include "Logger.hpp"
#include "DataStore.hpp"
#include "CLIHandler.hpp"

std::mutex m;
std::condition_variable cv;
std::atomic<bool> running = true;

static bool createDirectoryIfNotExists(const std::string& path) {
    struct stat st;
    if (stat(path.c_str(), &st) != 0) {
        // Directory does not exist; try to create it
        if (mkdir(path.c_str(), 0755) != 0) {
            LOG_ERROR << "Failed to create directory '" << path 
                      << "': " << std::strerror(errno) << std::endl;
            return false;
        }
    } else if (!S_ISDIR(st.st_mode)) {
        LOG_INFO << "Path '" << path << "' exists but is not a directory!" << std::endl;
        return false;
    }
    return true;
}


static void catchExitSignals() {
    auto sigHandler = [](int){
      std::lock_guard<std::mutex> guard(m);
      running = false;
      cv.notify_all();
    };
  
    /* Catch signals SIGINT and SIGTERM */
    if (signal(SIGINT, sigHandler) == SIG_ERR || 
        signal(SIGTERM, sigHandler) == SIG_ERR) {
      LOG_ERROR << "Failed to set up signal handler for SIGINT or SIGTERM" << std::endl;
      exit(EXIT_FAILURE);
    }
}

int main()
{
    catchExitSignals();

    LOG_INFO << "Starting KVPStorage App.." << std::endl;

    std::string dbDir = "../data";

    if (!createDirectoryIfNotExists(dbDir)) {
        LOG_ERROR << "Unable to proceed without data directory." << std::endl;
        return EXIT_FAILURE;
    }
    
    std::string dbPath = dbDir + "/IQ_HUB.db";
    
    std::string tableName = "kVP";
    DatabaseType dbType   = DatabaseType::SQLITE; 

    // Create and initialize the KV store
    DataStore storeData(dbPath, tableName, dbType);

    // Create CLI Handler and run it
    CLIHandler cli(storeData);
    cli.start();

    {
        std::unique_lock<std::mutex> guard(m);
        cv.wait(guard, [] {
            return !running;
        });
    }

    cli.stop();  // Stop CLI handler after the signal

    LOG_INFO << "KVPStorage App stopped" << std::endl;
    return 0;
}
