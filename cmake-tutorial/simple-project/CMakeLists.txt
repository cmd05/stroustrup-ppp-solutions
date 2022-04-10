cmake_minimum_required(VERSION 3.10)

project(Simple_Project 
        VERSION 1.0
        LANGUAGES CXX)

add_library(MyLib simple_lib.cpp simple_lib.hpp)

add_executable(MyExample simple_example.cpp)

# Make sure you link your targets with this command. It can also link libraries and
# even flags, so linking a target that does not exist will not give a configure-time error.
target_link_libraries(MyExample PRIVATE MyLib)

# This part is so the Modern CMake book can verify this example builds. For your code,
# you'll probably want tests too
# enable_testing()
# add_test(NAME MyExample COMMAND MyExample)