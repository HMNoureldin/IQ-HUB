# Set the include directories for IPCFifoHandler
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Create the IPCFifoHandler static library
add_library(IPCFifoHandler 
    STATIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/IPCFifoHandler.cpp
)

target_link_libraries(IPCFifoHandler
    PUBLIC
    Logger
    DBFactory
    DataStore
)

# Expose headers for IPCFifoHandler
target_include_directories(IPCFifoHandler 
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR} 
    ${CMAKE_SOURCE_DIR}/CommHandlers # for IInterface.hpp 
)
