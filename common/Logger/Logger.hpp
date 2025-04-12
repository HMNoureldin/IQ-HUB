#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <sstream>
#include <string>
#include <mutex>
#include <memory>
#include <chrono>
#include <iomanip>


// Log levels
#define LOG_LEVEL_DEBUG "DEBUG"
#define LOG_LEVEL_INFO  "INFO"
#define LOG_LEVEL_WARN  "WARN"
#define LOG_LEVEL_ERROR "ERROR"

// file name extraction 
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/* Logs macros*/
#define LOG_DEBUG Logger::getInstance().logMsg(LOG_LEVEL_DEBUG, __FILENAME__, __LINE__)
#define LOG_INFO  Logger::getInstance().logMsg(LOG_LEVEL_INFO , __FILENAME__, __LINE__)
#define LOG_WARN  Logger::getInstance().logMsg(LOG_LEVEL_WARN , __FILENAME__, __LINE__)
#define LOG_ERROR Logger::getInstance().logMsg(LOG_LEVEL_ERROR, __FILENAME__, __LINE__)

class Logger
{
private:
    // Sigleton instance
    static Logger  * instance_;
    static std::mutex mutex_;

    // Private constructor 
    Logger() = default;

public:
    // Logger Singelton Access
    static Logger& getInstance();
    
    // Log function declaration 
    std::ostream& logMsg(std::string level, const char * file, int line);

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(Logger&&) = delete;
    ~Logger();


};

#endif // LOGGER_H