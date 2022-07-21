cmake_minimum_required(VERSION 3.10)

project(Template_Vector VERSION 1.0 LANGUAGES CXX)

# add_library(vector_lib vector.h)
add_library(vector_base Vector_Base.h)
add_library(book Book.h)
add_library(dbg Debug.h)

set_target_properties(vector_base PROPERTIES LINKER_LANGUAGE CXX)
# set_target_properties(vector_lib PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(book PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(dbg PROPERTIES LINKER_LANGUAGE CXX)

add_executable(out main.cpp)

# target_link_libraries(out PRIVATE vector_lib)
target_link_libraries(out PRIVATE vector_base)
target_link_libraries(out PRIVATE book)
target_link_libraries(out PRIVATE dbg)