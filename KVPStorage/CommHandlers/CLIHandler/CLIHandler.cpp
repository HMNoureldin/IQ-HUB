#include "CLIHandler.hpp"


CLIHandler::CLIHandler(DataStore& store):
    storeData_(store),
    stopApp_{false} {
    LOG_INFO << "CLIHandler Constructed" << std::endl;
}

void CLIHandler::start() {
    LOG_INFO << "CLIHandler Start" << std::endl;
    runThread_ = std::thread(&CLIHandler::run, this);
}

void CLIHandler::stop() {
    stopApp_ = true;
    LOG_WARN << "Stopping CLIHandler...." << std::endl;
}

void CLIHandler::run() 
{
    std::string line;
    
    while (!stopApp_) {

        if (!std::getline(std::cin, line)) { 
            // Exit loop if input stream is closed
            stopApp_ = true;
        }

        std::istringstream iss(line);
        std::string cmd, key, value;
        iss >> cmd;

        if (cmd == "SET") {
            iss >> key >> value;
            if (storeData_.set(key, value)){
                LOG_INFO << "OK" << std::endl;
            } else{
                LOG_INFO << "FAIL" << std::endl;
            }
        } else if (cmd == "GET") {
            std::string value;
            iss >> key;
            storeData_.get(key, value);
            LOG_INFO << value << std::endl;            
            
        } else if (cmd == "DELETE") {
            iss >> key;
            if (storeData_.del(key)){
                LOG_INFO << "OK" << std::endl;
            } else {
                LOG_ERROR << "NOT FOUND" << std::endl;
            }
        } else {
            std::cout << "Unknown command\n";
        }
    }

    LOG_WARN << "CLIHandler App stopped" << std::endl;
}

CLIHandler::~CLIHandler(){
    LOG_WARN << "CLIHandler Destructed" << std::endl;
    stop();
}