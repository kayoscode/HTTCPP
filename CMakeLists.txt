cmake_minimum_required(VERSION 3.0)

SET(PROJ_NAME HTTCPP)
project(${PROJ_NAME})

add_subdirectory(CPPCrypto)

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

target_link_libraries(${PROJ_NAME} 
    CPPCrypto
)

target_include_directories("${PROJ_NAME}" PRIVATE ${PROJECT_SOURCE_DIR}/./include)
target_include_directories("${PROJ_NAME}" PRIVATE ${PROJECT_SOURCE_DIR}/CPPCrypto/include)