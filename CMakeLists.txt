cmake_minimum_required(VERSION 3.0)

SET(PROJ_NAME HTTCPP)
project(${PROJ_NAME})

file(GLOB SRC 
    "src/TLS/*.cpp"
    "src/windows/*.cpp"
    "src/linux/*.cpp"
    "src/macos/*.cpp"
    "src/*.cpp"
    "include/*.h"
    "include/TLS/*.h"
)

add_executable(${PROJ_NAME}
    "${SRC}"
)

target_include_directories("${PROJ_NAME}" PRIVATE ${PROJECT_SOURCE_DIR}/./include)