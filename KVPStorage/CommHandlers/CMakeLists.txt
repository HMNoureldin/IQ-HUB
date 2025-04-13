# Set include directories for the entire CommHandlers folder
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)


# Add subdirectories for the individual
# components (CLIHandler, IPCDBusHandler, 
# IPCFifoHandler,IPCSocketsHandler, CommHandlerFactory)
add_subdirectory(CLIHandler)
add_subdirectory(IPCDBusHandler)
add_subdirectory(IPCFifoHandler)
add_subdirectory(IPCSocketsHandler)
add_subdirectory(CommHandlerFactory)


