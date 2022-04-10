##### ------------------- BASICS ------------------- #####

## Conventional Run
# ~/package $ mkdir build
# ~/package $ cd build
# ~/package/build $ cmake ..
# ~/package/build $ make

## Single Line CMake build
# cmake -S project -B build -G "MinGW Makefiles"
# make -C build
# build\MyExample

cmake_minimum_required(VERSION 3.12)

project(MyProject VERSION 1.0
                  DESCRIPTION "cmake good."
                  LANGUAGES CXX
       )

# Make an executable
add_executable(one two.cpp three.h)

# Making a library
# ...

# target_include_directories: adds an include directory to a target
target_include_directories(one PUBLIC include) # add include dir "/include" to target "one"

# target_link_libraries
# It takes a target (another) and adds a dependency if a target is given
# If no target of that name (one) exists, then it adds a link to a library called one on your path (hence the name of the command)

add_library(another STATIC another.cpp another.h)
target_link_libraries(another PUBLIC one)

##### ------------------- VARIABLES AND CACHE ------------------- #####

set(MY_VAR "val")

# Access: ${MY_VARIABLE}

if():
    set(VAR_2 "val2" PARENT_SCOPE) # Has scope greater than current scope  
endif()

set(MY_LIST "one" "two")

# separate_arguments will turn a space separated string into a list (inplace).

# When a variable is expanded using ${} syntax, all the same rules about spaces apply

# Paths may contain a space at any time and should always be quoted when they are a variable 
# (never write ${MY_PATH}, always should be "${MY_PATH}").

# Environment variables 
set(ENV{ENV_MYVAR} 10)

##### ------------------- PROGRAMMING IN CMAKE ------------------- #####

# Control Flow
if(variable)
    # If variable is `ON`, `YES`, `TRUE`, `Y`, or non zero number
else()
    # If variable is `0`, `OFF`, `NO`, `FALSE`, `N`, `IGNORE`, `NOTFOUND`, `""`, or ends in `-NOTFOUND`
endif()
# If variable does not expand to one of the above, CMake will expand it then try again

# Functions and Macros

function(SIMPLE REQUIRED_ARG)
	message(STATUS "Simple arguments: ${REQUIRED_ARG}, followed by ${ARGN}")
	set(${REQUIRED_ARG} "from SIMPLE" PARENT_SCOPE)
endfunction()
# CMake does not have return values by setting variables

simple(This Foo Bar)
message("Output: ${This}")

# -- Simple arguments: This, followed by Foo;Bar
# Output: From SIMPLE

function(COMPLEX)
	cmake_parse_arguments(
		COMPLEX_PREFIX
		"SINGLE;ANOTHER"
		"ONE_VALUE;ALSO_ONE_VALUE"
		"MULTI_VALUES"
		${ARGN}
	)
endfunction()

complex(SINGLE ONE_VALUE value MULTI_VALUES some other values)

##### ------------------- COMMUNICATION IN CODE ------------------- #####

## Configure File

# This command copies a file (traditionally ending in .in) from one place to another,
# substituting all CMake variables it finds

# Config.h.in

#[[
# pragma once

# define MY_VERSION_MAJOR @PROJECT_VERSION_MAJOR@
# define MY_VERSION_MINOR @PROJECT_VERSION_MINOR@
# define MY_VERSION_PATCH @PROJECT_VERSION_PATCH@
# define MY_VERSION_TWEAK @PROJECT_VERSION_TWEAK@
# define MY_VERSION "@PROJECT_VERSION@"
]]

# Replace .in with .h file
configure_file (
    "${PROJECT_SOURCE_DIR}/include/My/Version.h.in"
    "${PROJECT_BINARY_DIR}/include/My/Version.h"
)

## Reading files
# ...

##### ------------------- HOW TO STRUCTURE PROJECT ------------------- #####

# First, this is what your files should look like when you start if your project is creatively called project,
# with a library called lib, and a executable called app:

#[[
- project
  - .gitignore
  - README.md
  - LICENCE.md
  - CMakeLists.txt
  - cmake
    - FindSomeLib.cmake
    - something_else.cmake
  - include
    - project
      - lib.hpp
  - src
    - CMakeLists.txt
    - lib.cpp
  - apps
    - CMakeLists.txt
    - app.cpp
  - tests
    - CMakeLists.txt
    - testlib.cpp
  - docs
    - CMakeLists.txt
  - extern
    - googletest
  - scripts
    - helper.py
]]

## Require out-of-source builds - top CMakeLists.txt
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

