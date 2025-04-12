#include "Logger.hpp"

// Initialize static members
Logger * Logger::instance_ = nullptr;
std::mutex Logger::mutex_;


Logger& Logger::getInstance(){
    std::lock_guard<std::mutex> lock(mutex_);
    if (!instance_){
        instance_ = new Logger();
    }
    return * instance_;
}

std::ostream& Logger::logMsg(std::string level, const char * file, int line){
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);

    std::cout << std::put_time(std::localtime(&time), "%Y-%m-%d %T")
              << " [" << level << "] " << file << ":" << line << " - ";
    return std::cout;
}

Logger::~Logger() {
    delete instance_;
}


