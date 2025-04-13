#include "CommHandlerFactory.hpp"

std::unique_ptr<ICommHandler> CommHandlerFactory::createCommHandler( 
    CommHandlerType CommType, DataStore& DataStore) {
        if (CommType == CommHandlerType::CLI) {
            return std::make_unique<CLIHandler>(DataStore);
        } else if (CommType == CommHandlerType::D_BUS) {
            return std::make_unique<IPCDBusHandler>(DataStore);
        } else if (CommType == CommHandlerType::FIFO) {
            return std::make_unique<IPCFifoHandler>(DataStore);
        } else if (CommType == CommHandlerType::SOCKETS) {
            return std::make_unique<IPCSocketsHandler>(DataStore);
        }
    return nullptr;
}