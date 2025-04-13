# Set the include directories for CLIHandler
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Create the CLIHandler static library
add_library(CLIHandler 
    STATIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/CLIHandler.cpp
)

target_link_libraries(CLIHandler
    PUBLIC
    Logger
    DBFactory
    DataStore
)
# Expose headers for CLIHandler
target_include_directories(CLIHandler 
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}  
    # ${CMAKE_SOURCE_DIR}/KVPStorage/DataStore
    ${CMAKE_SOURCE_DIR}/CommHandlers
)
