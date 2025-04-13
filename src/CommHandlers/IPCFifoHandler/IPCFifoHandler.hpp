#ifndef IPC_FIFO_HANDLER_H
#define IPC_FIFO_HANDLER_H

#include  <thread>
#include  <atomic>
#include "Logger.hpp"
#include "ICommHandler.hpp"


class IPCFifoHandler : public ICommHandler {
    private:
        DataStore&          storeData_;
        std::atomic<bool>   stopApp_;
        std::thread         runThread_;

    public:
        IPCFifoHandler(DataStore& store);
        void start () override;
        void stop()   override;
        ~IPCFifoHandler() override;
    
    private:
        void run();
};


#endif //IPC_FIFO_HANDLER_H
