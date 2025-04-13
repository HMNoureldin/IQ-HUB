#ifndef IPC_D_BUS_HANDLER_H
#define IPC_D_BUS_HANDLER_H

#include "Logger.hpp"
#include "ICommHandler.hpp"



class IPCDBusHandler : public ICommHandler {
    public:
        void run(DataStore& store) override;
};


#endif //IPC_D_BUS_HANDLER_H