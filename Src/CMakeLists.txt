cmake_minimum_required(VERSION 3.0.0)

project(altparser VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CLI_FILES
    Cli/cli.cpp
    Cli/cli.h
    Cli/help.cpp
    Cli/help.h
)


add_executable(altparser main.cpp ${CLI_FILES})

set_target_properties( 
    altparser PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON 
)


