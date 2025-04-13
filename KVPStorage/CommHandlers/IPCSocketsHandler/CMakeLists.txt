# Set the include directories for IPCSocketsHandler
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Create the IPCSocketsHandler static library
add_library(IPCSocketsHandler 
    STATIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/IPCSocketsHandler.cpp
)

target_link_libraries(IPCSocketsHandler
    PUBLIC
    Logger
    DBFactory
    DataStore
)

# Expose headers for IPCSocketsHandler
target_include_directories(IPCSocketsHandler 
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR} 
    ${CMAKE_SOURCE_DIR}/CommHandlers # for IInterface.hpp 
)
