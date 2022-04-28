cmake_minimum_required(VERSION 3.10)

project(Vector_Class VERSION 1.0 LANGUAGES CXX)

add_library(vector_lib vector.cpp vector.h)
add_executable(out main.cpp)

target_link_libraries(out PRIVATE vector_lib)
set(ENV{CMAKE_GENERATOR} "MinGW Makefiles")
