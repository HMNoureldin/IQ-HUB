# Set the include directories for IPCDBusHandler
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Create the IPCDBusHandler static library
add_library(IPCDBusHandler 
    STATIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/IPCDBusHandler.cpp
)

target_link_libraries(IPCDBusHandler
    PUBLIC
    Logger
    DBFactory
    DataStore
)

# Expose headers for IPCDBusHandler
target_include_directories(IPCDBusHandler 
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR} 
    ${CMAKE_SOURCE_DIR}/CommHandlers # for IInterface.hpp 
)
