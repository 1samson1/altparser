cmake_minimum_required(VERSION 3.14)

project(libaltparser VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCES 
    lib.cpp
    lib.h
)

add_library(libaltparser SHARED ${SOURCES})

set_target_properties( 
    libaltparser PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON 
)


# FIND CURL ########################################

find_package(CURL REQUIRED)

if(NOT CURL_FOUND)
    message(SEND_ERROR "Failed to find CURL")
    return()    
else()
    target_include_directories(libaltparser PRIVATE ${CURL_INCLUDE_DIR})
endif()


# LINK ############################################

target_link_libraries(libaltparser ${CURL_LIBRARIES})

