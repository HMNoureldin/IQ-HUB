# Create the Logger static library
add_library(Logger STATIC ${CMAKE_CURRENT_SOURCE_DIR}/Logger.cpp)

# Specify that Logger exposes headers from the current directory
target_include_directories(Logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})