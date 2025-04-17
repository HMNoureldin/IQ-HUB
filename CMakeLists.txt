cmake_minimum_required(VERSION 3.14)
project(kvpstorage)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the executable
add_executable(${PROJECT_NAME} kvpstorage.cpp)

# Add the common directory (if it's at the root level)
add_subdirectory(${CMAKE_SOURCE_DIR}/common)
add_subdirectory(${CMAKE_SOURCE_DIR}/src)

target_link_libraries(kvpstorage PRIVATE Logger DBFactory DataStore CommHandlerFactory pthread)

# This is important! Ensures Buildroot's install logic works
install(TARGETS ${PROJECT_NAME} DESTINATION bin)

