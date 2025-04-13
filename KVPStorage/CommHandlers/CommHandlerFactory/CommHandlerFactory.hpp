#ifndef COMM_HANDLER_FACTORY_H
#define COMM_HANDLER_FACTORY_H

#include <memory>
#include <string>

#include "ICommHandler.hpp"
#include "CLIHandler.hpp"
#include "IPCDBusHandler.hpp"
#include "IPCFifoHandler.hpp"
#include "IPCSocketsHandler.hpp"


enum class CommHandlerType {
    CLI,
    D_BUS,
    FIFO,
    SOCKETS
};


const auto CommandHandlerTypeToString = [](CommHandlerType type) -> std::string {
    switch (type) {
        case CommHandlerType::CLI:
            return "CLI";
        case CommHandlerType::D_BUS:
            return "D_BUS";
        case CommHandlerType::FIFO:
            return "FIFO";
        case CommHandlerType::SOCKETS:
            return "SOCKETS";
        default:
            return "UNKNOWN";
    }
};

class CommHandlerFactory {
    public:
        static std::unique_ptr<ICommHandler> createCommHandler(
            CommHandlerType CommType);
};

#endif //COMM_HANDLER_FACTORY_H