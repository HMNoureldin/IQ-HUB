#include <csignal>
#include <atomic>
#include "CLIHandler.hpp"

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

void CLIHandler::run(DataStore& store) 
{
    catchExitSignals();

    std::string line;
    
    while (running && std::getline(std::cin, line)) {
        std::istringstream iss(line);
        std::string cmd, key, value;
        iss >> cmd;

        if (cmd == "SET") {
            iss >> key >> value;
            std::cout << (store.set(key, value) ? "OK\n" : "FAIL\n");
        } else if (cmd == "GET") {
            iss >> key;
            // std::cout << store.get(key) << "\n";
        } else if (cmd == "DELETE") {
            iss >> key;
            // std::cout << (store.remove(key) ? "OK\n" : "NOT FOUND\n");
        } else {
            std::cout << "Unknown command\n";
        }
    }

    LOG_WARN << "CLIHandler App stopped" << std::endl;

}