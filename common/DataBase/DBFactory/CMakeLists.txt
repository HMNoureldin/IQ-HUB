# Set the include directories for DBFactory
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Link DBFactory against both SQLiteDB and NoSQLDB
add_library(DBFactory STATIC ${CMAKE_CURRENT_SOURCE_DIR}/DBFactory.cpp)

# Make sure DBFactory exposes headers from its own directory and from the root DataBase directory
target_include_directories(DBFactory 
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/..           # for IDatabase.hpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/../SQLiteDB  # for SQLiteDB.hpp
)

# Link DBFactory to SQLiteDB 
# TODO: add NoSQLDB or other database types
target_link_libraries(DBFactory PRIVATE SQLiteDB NoSQLDB)