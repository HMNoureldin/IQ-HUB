#ifndef IPC_FIFO_HANDLER_H
#define IPC_FIFO_HANDLER_H


#include "ICommHandler.hpp"
#include "Logger.hpp"


class IPCFifoHandler : public ICommHandler {
    public:
        void run(DataStore& store) override;
};


#endif //IPC_FIFO_HANDLER_H
