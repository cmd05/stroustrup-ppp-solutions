cmake_minimum_required(VERSION 3.10)

project(Text_Editor 
        VERSION 1.0
        LANGUAGES CXX)

# add_library(Ed Editor.h LANGUAGE CXX)

add_executable(out main.cpp)

# target_link_libraries(Text_Editor PRIVATE Ed)