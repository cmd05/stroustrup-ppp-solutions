cmake_minimum_required(VERSION 3.21)
project(Vector_Class)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES
    *.h
    *.cpp
)

add_executable(Vector_Class ${SOURCE_FILES} ${SOURCES})
