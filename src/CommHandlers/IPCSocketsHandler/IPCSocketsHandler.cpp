
#include "IPCSocketsHandler.hpp"

IPCSocketsHandler::IPCSocketsHandler(DataStore& store):
    storeData_(store),
    stopApp_{false} {
  LOG_INFO << "IPCSocketsHandler Constructed" << std::endl;
}

void IPCSocketsHandler::start() {
  LOG_INFO << "IPCSocketsHandler Start" << std::endl;
  runThread_ = std::thread(&IPCSocketsHandler::run, this);
}

void IPCSocketsHandler::stop() {
  stopApp_ = true;
  LOG_WARN << "Stopping IPCSocketsHandler...." << std::endl;
}

void IPCSocketsHandler::run() 
{

    while (!stopApp_ ){

      // TODO:: Add code logic here
      // Simulate some work or wait
      std::this_thread::sleep_for(std::chrono::seconds(1));

    }

    LOG_WARN << "IPCSocketsHandler stopped" << std::endl;

}

IPCSocketsHandler::~IPCSocketsHandler(){
  LOG_WARN << "IPCSocketsHandler Destructed" << std::endl;
  stop();
}