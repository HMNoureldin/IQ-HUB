#include <csignal>
#include <atomic>
#include <thread>
#include "IPCSocketsHandler.hpp"

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


void IPCSocketsHandler::run(DataStore& store) 
{
    catchExitSignals();

    while (running ){

        // Simulate some work or wait
        std::this_thread::sleep_for(std::chrono::seconds(1));

    }

    LOG_WARN << "IPCSocketsHandler stopped" << std::endl;

}