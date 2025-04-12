# Check for SQLite3 installation
find_package(SQLite3 REQUIRED)

# If SQLite3 is not found, an error will be raised
if (NOT SQLITE3_FOUND)
    message(FATAL_ERROR "SQLite3 is not installed or not found!")
endif()

# Set the include directories for SQLiteDB
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Create the SQLiteDB static library
add_library(SQLiteDB STATIC ${CMAKE_CURRENT_SOURCE_DIR}/SQLiteDB.cpp)

# Expose headers for SQLiteDB
target_include_directories(SQLiteDB PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/DataBase)

# Link SQLite3 to the SQLiteDB library
target_link_libraries(SQLiteDB PRIVATE SQLite::SQLite3)