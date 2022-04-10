cmake_minimum_required(VERSION 3.10)
project(SINGLE_LIB
		VERSION 1.0
		LANGUAGES CXX)

add_executable(project main.cpp)

add_subdirectory(src)

target_link_libraries(project PUBLIC MyMath)