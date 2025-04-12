#ifndef DATA_STORE_H
#define DATA_STORE_H

#include "DBFactory.hpp"
#include "Logger.hpp"

class DataStore {
    public:
        DataStore(const std::string& dbPath, const std::string& tableName, DatabaseType dbType);
        ~DataStore();
    
        bool open();
        void close();
    
        bool createTableIfNotExists();
        bool set(const std::string& key, const std::string& value);
        bool get(const std::string& key, std::string& value);
        bool del(const std::string& key);
    
    private:
        std::string dbPath_;
        std::string tableName_;
        DatabaseType dbType_;
        std::unique_ptr<IDatabase> db_;
};

#endif //DATA_STORE_H
