cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project("Terminus-Math")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(MATH_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/include")

include_directories("${MATH_INCLUDE_DIRS}")

add_executable(test test/main.cpp)