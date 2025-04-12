#ifndef DATABASE_INTERFACE_H
#define DATABASE_INTERFACE_H

#include <string>

class IDatabase
{
    public:
        virtual ~IDatabase() {}
        virtual bool open() = 0;
        virtual void close() = 0;
        virtual bool execute(const std::string& sql, std::string& result) = 0;
        virtual std::string getLastError() const = 0;
};

#endif //DATABASE_INTERFACE_H