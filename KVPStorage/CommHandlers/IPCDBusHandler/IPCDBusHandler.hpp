#ifndef IPC_D_BUS_HANDLER_H
#define IPC_D_BUS_HANDLER_H

#include  <thread>
#include  <atomic>
#include "Logger.hpp"
#include "ICommHandler.hpp"



class IPCDBusHandler : public ICommHandler {
    private:
        DataStore&          storeData_;
        std::atomic<bool>   stopApp_;
        std::thread         runThread_;
        
    public:
        IPCDBusHandler(DataStore& store);
        void start () override;
        void stop()   override;
        ~IPCDBusHandler() override;

    private:
        void run();
};


#endif //IPC_D_BUS_HANDLER_H