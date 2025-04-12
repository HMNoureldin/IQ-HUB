#include "SQLiteDB.hpp"
#include <iostream>
#include <sstream>

SQLiteDB::SQLiteDB(const std::string& dbPath) : 
    dbPath_(dbPath),
    db_(nullptr) {

}

bool SQLiteDB::open() {
    int rc = sqlite3_open(dbPath_.c_str(), &db_);
    if (rc != SQLITE_OK) {
        lastError_ = sqlite3_errmsg(db_);
        db_ = nullptr;
        return false;
    }
    return true;
}

void SQLiteDB::close() {
    if (db_) {
        sqlite3_close(db_);
        db_ = nullptr;
    }
}

bool SQLiteDB::execute(const std::string& sql, std::string& result) {
    char* errMsg = nullptr;
    result.clear(); // Clear the result string before execution

    // If the SQL is a SELECT statement, collect the results.
    int rc = sqlite3_exec(db_, sql.c_str(), callback, &result, &errMsg);

    if (rc != SQLITE_OK) {
        lastError_ = errMsg;
        sqlite3_free(errMsg);
        return false;
    }

    return true;
}


int SQLiteDB::callback(void* data, int argc, char** argv, char** azColName) {
    std::string* result = static_cast<std::string*>(data);

    // Format each row of the SELECT result as a string.
    std::stringstream row;
    for (int i = 0; i < argc; ++i) {
        row << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << " | ";
    }
    row << "\n";

    // Append the row to the result string.
    *result += row.str();

    return 0;
}

std::string SQLiteDB::getLastError() const {
    return lastError_;
}


SQLiteDB::~SQLiteDB() {
    close();
}
