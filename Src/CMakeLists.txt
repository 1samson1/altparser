cmake_minimum_required(VERSION 3.0.0)

project(altparser VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)


add_executable(altparser main.cpp ${UI_FILES})

set_target_properties( 
    altparser PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON 
)


