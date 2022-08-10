cmake_minimum_required(VERSION 3.14)

project(altpars VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCES 
    Src/download.cpp
    Src/download.h
)

add_library(altpars SHARED ${SOURCES})

set_target_properties( 
    altpars PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON 
)


# FIND CURL ########################################

find_package(CURL REQUIRED)

if(NOT CURL_FOUND)
    message(SEND_ERROR "Failed to find CURL")
    return()    
else()
    target_include_directories(altpars PRIVATE ${CURL_INCLUDE_DIR})
endif()

# FIND nlohmann json ###################################

find_package(nlohmann_json 3.2.0 REQUIRED)

if(NOT nlohmann_json_FOUND)
    message(SEND_ERROR "Failed to find nlohmann_json")
    return()    
endif()

# LINK ############################################

target_link_libraries(altpars PRIVATE
    ${CURL_LIBRARIES}
    nlohmann_json::nlohmann_json
)

