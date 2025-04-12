# Set the include directories for SQLiteDB
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Create the SQLiteDB static library
add_library(SQLiteDB STATIC ${CMAKE_CURRENT_SOURCE_DIR}/NoSQLDB.cpp)

# Expose headers for SQLiteDB
target_include_directories(SQLiteDB PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/DataBase)
