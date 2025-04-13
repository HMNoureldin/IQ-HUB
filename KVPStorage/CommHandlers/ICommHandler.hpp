#ifndef I_COMM_HANDLER_H
#define I_COMM_HANDLER_H

#include "DataStore.hpp"

class ICommHandler {
    public:
        virtual void start() = 0;
        virtual void stop()  = 0;
        virtual ~ICommHandler() = default;
};

#endif // I_COMM_HANDLER_H