#ifndef DATABASE_INTERFACE_H
#define DATABASE_INTERFACE_H

#include <string>

enum class Operation {
    CREATE,
    SET,
    GET,
    DEL
};

class IDatabase
{
    public:
        virtual ~IDatabase() {}
        virtual bool open() = 0;
        virtual void close() = 0;
        virtual bool execute(const std::string& sql, std::string& resultz, Operation op) = 0;
        virtual std::string getLastError() const = 0;
};

#endif //DATABASE_INTERFACE_H