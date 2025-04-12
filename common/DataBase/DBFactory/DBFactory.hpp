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


const auto databaseTypeToString = [](DatabaseType type) -> std::string {
    switch (type) {
        case DatabaseType::SQLITE:
            return "SQLITE";
        case DatabaseType::NOSQL:
            return "NOSQL";
        default:
            return "UNKNOWN";
    }
};

class DBFactory {
    public:
        static std::unique_ptr<IDatabase> createDatabase(
            DatabaseType dbType, const std::string& dbPath);
};

#endif //DB_FACTORY_H