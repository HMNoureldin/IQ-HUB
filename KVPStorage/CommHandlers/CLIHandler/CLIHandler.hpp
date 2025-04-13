#ifndef CLI_HANDLER_H
#define CLI_HANDLER_H

#include <thread>
#include <atomic>
#include "Logger.hpp"
#include "ICommHandler.hpp"


class CLIHandler : public ICommHandler {
    private:
        DataStore&          storeData_;
        std::atomic<bool>   stopApp_;
        std::thread         runThread_;

    public:
        CLIHandler(DataStore& store);
        void start () override;
        void stop()   override;
        ~CLIHandler() override;
    
    private:
        void run();
};

#endif //CLI_HANDLER_H