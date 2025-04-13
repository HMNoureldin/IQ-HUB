# Create the DataStore static library
add_library(DataStore STATIC ${CMAKE_CURRENT_SOURCE_DIR}/DataStore.cpp)

# Specify that DataStore exposes headers from the current directory
target_include_directories(DataStore 
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(DataStore PUBLIC Logger DBFactory)
