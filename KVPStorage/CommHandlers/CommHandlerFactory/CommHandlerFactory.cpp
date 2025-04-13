#include "CommHandlerFactory.hpp"

std::unique_ptr<ICommHandler> CommHandlerFactory::createCommHandler( 
    CommHandlerType CommType) {
        if (CommType == CommHandlerType::CLI) {
            return std::make_unique<CLIHandler>();
        } else if (CommType == CommHandlerType::D_BUS) {
            return std::make_unique<IPCDBusHandler>();
        } else if (CommType == CommHandlerType::FIFO) {
            return std::make_unique<IPCFifoHandler>();
        } else if (CommType == CommHandlerType::SOCKETS) {
            return std::make_unique<IPCSocketsHandler>();
        }
    return nullptr;
}