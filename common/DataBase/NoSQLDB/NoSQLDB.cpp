#include "NoSQLDB.hpp"


NoSQLDB::NoSQLDB(const std::string& dbPath) : 
    dbPath_(dbPath) {
}

bool NoSQLDB::open() {
    bool result = false;
    std::cout << "NoSQLDB: open() "<< std::endl;
    /*TODO :: Add Impl*/
    return result;
}

void NoSQLDB::close() {
    std::cout << "NoSQLDB: close() "<< std::endl;
    /*TODO :: Add Impl*/
}

bool NoSQLDB::execute(const std::string& sql, std::string& result, Operation op) {
    bool exResult = false;
    std::cout << "NoSQLDB: execute() "<< std::endl;
    /*TODO :: Add Impl*/
    return exResult;
}

std::string NoSQLDB::getLastError() const {
    return lastError_;
}


NoSQLDB::~NoSQLDB() {
    close();
}
