cmake_minimum_required(VERSION 3.14)
project(KVPStorage)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the executable
add_executable(${PROJECT_NAME} main.cpp)


# Add the common directory (if it's at the root level)
add_subdirectory(${CMAKE_SOURCE_DIR}/common)
add_subdirectory(${CMAKE_SOURCE_DIR}/src)

target_link_libraries(KVPStorage PRIVATE Logger DBFactory DataStore CommHandlerFactory)

