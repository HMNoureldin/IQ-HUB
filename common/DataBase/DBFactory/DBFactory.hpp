#ifndef DB_FACTORY_H
#define DB_FACTORY_H

#include <memory>
#include <string>

#include "IDatabase.hpp"
#include "SQLiteDB.hpp"


enum class DatabaseType {
    SQLITE,
    NOSQL
};

class DBFactory {
    public:
        static std::unique_ptr<IDatabase> createDatabase(
            DatabaseType dbType, const std::string& dbPath);
};

#endif //DB_FACTORY_H