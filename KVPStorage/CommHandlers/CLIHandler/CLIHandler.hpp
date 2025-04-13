#ifndef CLI_HANDLER_H
#define CLI_HANDLER_H

#include "Logger.hpp"
#include "ICommHandler.hpp"



class CLIHandler : public ICommHandler {
    public:
        void run(DataStore& store) override;
};

#endif //CLI_HANDLER_H