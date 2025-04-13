#ifndef I_COMM_HANDLER_H
#define I_COMM_HANDLER_H

#include "DataStore.hpp"

class ICommHandler {
    public:
        virtual void run(DataStore& store) = 0;
        virtual ~ICommHandler() = default;
};

#endif // I_COMM_HANDLER_H