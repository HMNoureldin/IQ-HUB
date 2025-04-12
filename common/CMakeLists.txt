add_library(Logger
    Logger/Logger.cpp
)

target_include_directories(Logger PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Logger)
