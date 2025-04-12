cmake_minimum_required(VERSION 3.14)
project(KVPStorage)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the executable
add_executable(${PROJECT_NAME} KVPStorage.cpp)

# Add subdirectories
add_subdirectory(common)

target_link_libraries(KVPStorage PRIVATE Logger)

