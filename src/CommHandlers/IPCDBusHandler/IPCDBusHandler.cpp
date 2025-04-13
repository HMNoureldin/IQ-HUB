#include "IPCDBusHandler.hpp"

IPCDBusHandler::IPCDBusHandler(DataStore& store):
    storeData_(store),
    stopApp_{false} {
  LOG_INFO << "IPCDBusHandler Constructed" << std::endl;
}

void IPCDBusHandler::start() {
  LOG_INFO << "IPCDBusHandler Start" << std::endl;
  runThread_ = std::thread(&IPCDBusHandler::run, this);
}

void IPCDBusHandler::stop() {
  stopApp_ = true;
  LOG_WARN << "Stopping IPCDBusHandler...." << std::endl;
}

void IPCDBusHandler::run() 
{

    while (!stopApp_){

      // TODO:: Add code logic here
      // Simulate some work or wait
      std::this_thread::sleep_for(std::chrono::seconds(1));

    }

    LOG_WARN << "IPCDBusHandler stopped" << std::endl;
}

IPCDBusHandler::~IPCDBusHandler(){
  LOG_WARN << "IPCDBusHandler Destructed" << std::endl;
  stop();
}