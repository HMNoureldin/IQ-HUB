# Set include directories for the entire DataBase folder
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Add subdirectories for the individual components (SQLiteDB, NoSQLDB, DBFactory)
add_subdirectory(SQLiteDB)
# add_subdirectory(NoSQLDB)
add_subdirectory(DBFactory)