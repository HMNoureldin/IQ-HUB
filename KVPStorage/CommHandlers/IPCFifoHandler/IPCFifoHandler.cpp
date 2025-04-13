#include "IPCFifoHandler.hpp"

IPCFifoHandler::IPCFifoHandler(DataStore& store):
    storeData_(store),
    stopApp_{false} {
  LOG_INFO << "IPCFifoHandler Constructed" << std::endl;
}

void IPCFifoHandler::start() {
  LOG_INFO << "IPCFifoHandler Start" << std::endl;
  runThread_ = std::thread(&IPCFifoHandler::run, this);
}

void IPCFifoHandler::stop() {
  stopApp_ = true;
  LOG_WARN << "Stopping IPCFifoHandler...." << std::endl;
}


void IPCFifoHandler::run() 
{

    while (!stopApp_ ){
        // TODO:: Add code logic here
        // Simulate some work or wait
        std::this_thread::sleep_for(std::chrono::seconds(1));

    }

    LOG_WARN << "IPCFifoHandler stopped" << std::endl;
}

IPCFifoHandler::~IPCFifoHandler(){
  LOG_WARN << "IPCFifoHandler Destructed" << std::endl;
  stop();
}