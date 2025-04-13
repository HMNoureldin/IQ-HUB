#include <iostream>
#include <csignal>
#include <atomic>
#include <thread>
#include <mutex>
#include <filesystem>
#include <condition_variable>
#include "Logger.hpp"
#include "DataStore.hpp"
#include "CLIHandler.hpp"

std::mutex m;
std::condition_variable cv;
std::atomic<bool> running = true;


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

    // Ensure data directory exists
    std::filesystem::path dbDir = ".." / std::filesystem::path("data");
    std::filesystem::create_directories(dbDir);
    std::string dbPath = (dbDir / "IQ_HUB.db").string();

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