#include <iostream>
#include <csignal>
#include <atomic>
#include <thread>
#include "Logger.hpp"
#include "DataStore.hpp"

std::atomic<bool> running = true;


static void catchExitSignals() {
    auto sigHandler = [](int){
      running = false;
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

    // // Example: User selects database type at runtime (can be via config or user input)
    // DatabaseType dbType = DatabaseType::SQLITE;  // or DatabaseType::NOSQL
    // std::string dbPath = "IQ_HUB.db";
    // std::string tableName = "kVP";

    // // Create and open the KVP store interface
    // DataStore store(dbPath, tableName, dbType);
    
    // if (!store.open()) {
    //   LOG_ERROR << "Failed to open database!" << std::endl;
    //   return 1;
    // }

    // // Set a key-value pair
    // if (store.set("username", "Hesham")) {
    //   LOG_INFO << "Set operation successful!" << std::endl;
    // } else {
    //   LOG_ERROR << "Set operation failed!" << std::endl;
    // }

    // // Get the value of a key
    // std::string value;
    // if (store.get("username", value)) {
    //   LOG_INFO << "Got value: " << value << std::endl;
    // } else {
    //   LOG_ERROR << "Get operation failed!" << std::endl;
    // }

    // // Delete a key-value pair
    // if (store.del("username")) {
    //   LOG_INFO << "Delete operation successful!" << std::endl;
    // } else {
    //   LOG_ERROR << "Delete operation failed!" << std::endl;
    // }

    // // Close the database
    // store.close();

    while (running) {
        // Simulate some work or wait
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    LOG_INFO << "KVPStorage App stopped" << std::endl;

    return 0;
}