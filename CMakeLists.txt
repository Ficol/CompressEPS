cmake_minimum_required(VERSION 3.5)
project(CompressEPS)
enable_testing()

include_directories("${PROJECT_SOURCE_DIR}/src")
set(CMAKE_CXX_FLAGS "--std=c++14 -Wall -pedantic -Wextra")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(src)
add_subdirectory(test)


