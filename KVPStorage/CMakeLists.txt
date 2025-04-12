add_library(KVPStorage_LIB src/DataStore.cpp)

target_include_directories(KVPStorage_LIB PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(KVPStorage_LIB PUBLIC DBFactory Logger)