#ifndef IPC_SOCKETS_HANDLER_H
#define IPC_SOCKETS_HANDLER_H

#include "ICommHandler.hpp"
#include "Logger.hpp"


class IPCSocketsHandler : public ICommHandler {
    public:
        void run(DataStore& store) override;
};


#endif //IPC_SOCKETS_HANDLER_H