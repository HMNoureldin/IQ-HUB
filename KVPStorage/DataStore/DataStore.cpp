#include "DataStore.hpp"


DataStore::DataStore(const std::string& dbPath, const std::string& tableName , DatabaseType dbType)
    : dbPath_(dbPath), tableName_(tableName), dbType_(dbType) {}

bool DataStore::open(){

    LOG_INFO << "Opening database at: " << dbPath_ 
             << " (Type: " << databaseTypeToString(dbType_) 
             << ", Table: " << tableName_ << ")" << std::endl;

    db_ = DBFactory::createDatabase(dbType_, dbPath_);
    bool isOpen = db_->open();

    if (!isOpen) {
        LOG_ERROR << db_->getLastError() << std::endl;
        return false;
    }

    // Create the key_value_store table if it doesn't exist
    return createTableIfNotExists();
}

void DataStore::close() {
    LOG_INFO << "Closing database connection" << std::endl;
    
    if (db_) {
        db_->close();
    }
}

bool DataStore::createTableIfNotExists() {
    std::string sql = \
        "CREATE TABLE IF NOT EXISTS " + tableName_ + \
        " (key TEXT, value TEXT NOT NULL);";
    std::string result;
    
    bool isExecuted = db_->execute(sql, result);

    if (!isExecuted) {
        LOG_ERROR << db_->getLastError() << std::endl;
        return false;
    }
    return isExecuted;
}

bool DataStore::set(const std::string& key, const std::string& value){
    LOG_INFO << "Setting key: " << key 
            << ", Value: " << value << std::endl;
    
            std::string sql = \
        "INSERT INTO " + tableName_ + " (key, value) VALUES ('" + \
        key + "', '" + value + "');";
    std::string result;

    bool isExecuted = db_->execute(sql, result);

    if (!isExecuted) {
        LOG_ERROR << db_->getLastError() << std::endl;
        return false;
    }
    return isExecuted;
}

bool DataStore::get(const std::string& key, std::string& value){
    LOG_INFO << "Getting value for key: " << key << std::endl;
    
    std::string sql = \
        "SELECT value FROM " + tableName_ + \
        " WHERE key = '" + key + "';";
    std::string result;

    bool isExecuted = db_->execute(sql, result);

    if (isExecuted) {
        value = result;  // Assuming result contains the value
        return isExecuted;
    } else {
        LOG_ERROR << db_->getLastError() << std::endl;
        return false;
    }
}

bool DataStore::del(const std::string& key){
    LOG_INFO << "Deleting key: " << key << std::endl;
    
    std::string sql = \
        "DELETE FROM " + tableName_ + \
        " WHERE key = '" + key + "';";
    std::string result;

    bool isExecuted = db_->execute(sql, result);

    if (!isExecuted) {
        LOG_ERROR << db_->getLastError() << std::endl;
        return false;
    }
    return isExecuted;
}


DataStore::~DataStore() {
    close();
}