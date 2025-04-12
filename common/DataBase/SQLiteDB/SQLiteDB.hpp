#ifndef SQL_LITE_DB_H
#define SQL_LITE_DB_H

#include <sqlite3.h>
#include <string>
#include <vector>
#include <map>

#include "IDatabase.hpp"

class SQLiteDB : public IDatabase
{
    private:
        sqlite3* db_;
        std::string dbPath_;
        std::string lastError_;
        
    public:
            SQLiteDB(const std::string& dbPath);

            bool open();
            void  close();

            bool execute(const std::string& sql, std::string& result);
            std::string getLastError() const;

            ~SQLiteDB();

        private:
            static int callback(void* data, int argc, char** argv, char** azColName);
};

#endif //SQL_LITE_DB_H