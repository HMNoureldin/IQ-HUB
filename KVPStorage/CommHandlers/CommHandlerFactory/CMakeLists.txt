# Set the include directories for CommHandlerFactory
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(CommHandlerFactory 
    STATIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/CommHandlerFactory.cpp
)

# Make sure CommHandlerFactory exposes headers from 
# its own directory and from the root CommInterfaces directory
target_include_directories(CommHandlerFactory 
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/..                  # for ICommHandler.hpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/../CLIHandler       # for CLIHandler.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../IPCDBusHandler   # for IPCDBusHandler.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../IPCFifoHandler   # for IPCFifoHandler.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../IPCSocketsHandler # for IPCSocketsHandler.hpp

    # 👇 Add this line:
    ${CMAKE_SOURCE_DIR}/include                     # 👈 for DataStore.hpp
)

# TODO: add IPCDBusHandler or other Handlers types
target_link_libraries(CommHandlerFactory PRIVATE CLIHandler)