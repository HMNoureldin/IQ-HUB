#ifndef IPC_SOCKETS_HANDLER_H
#define IPC_SOCKETS_HANDLER_H

#include <thread>
#include <atomic>
#include "ICommHandler.hpp"
#include "Logger.hpp"


class IPCSocketsHandler : public ICommHandler {
    private:
        DataStore&          storeData_;
        std::atomic<bool>   stopApp_;
        std::thread         runThread_;

    public:
        IPCSocketsHandler(DataStore& store);
        void start () override;
        void stop()   override;
        ~IPCSocketsHandler() override;

    private:
        void run() ;
};


#endif //IPC_SOCKETS_HANDLER_H