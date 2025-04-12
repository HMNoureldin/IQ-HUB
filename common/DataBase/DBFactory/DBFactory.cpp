#include "DBFactory.hpp"

std::unique_ptr<IDatabase> DBFactory::createDatabase( 
    DatabaseType dbType, const std::string& dbPath) {
        if (dbType == DatabaseType::SQLITE) {
            return std::make_unique<SQLiteDB>(dbPath);
        }   
        return nullptr;
}