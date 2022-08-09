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

target_link_libraries(altparser libaltparser)


