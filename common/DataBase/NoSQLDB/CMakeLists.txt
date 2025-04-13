# Set the include directories for SQLiteDB
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Create the NoSQLDB static library
add_library(NoSQLDB STATIC ${CMAKE_CURRENT_SOURCE_DIR}/NoSQLDB.cpp)

# Expose headers for SQLiteDB
target_include_directories(NoSQLDB PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/DataBase)
