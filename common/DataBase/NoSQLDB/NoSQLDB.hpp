#ifndef NO_SQL_DB_H
#define NO_SQL_DB_H


#include <string>
#include <vector>
#include <map>
#include <iostream>

#include "IDatabase.hpp"

class NoSQLDB : public IDatabase
{
    private:
        std::string dbPath_;
        std::string lastError_;
        
    public:
            NoSQLDB(const std::string& dbPath);
            bool open() override;
            void  close() override;
            bool execute(const std::string& sql, std::string& result, Operation op) override;
            std::string getLastError() const override;

            ~NoSQLDB();
};



#endif // NO_SQL_DB_H