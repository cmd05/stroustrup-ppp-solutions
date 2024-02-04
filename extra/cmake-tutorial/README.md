## How to Run
```
## Conventional Run
~/package $ mkdir build
~/package $ cd build
~/package/build $ cmake ..
~/package/build $ make

## Single Line CMake build
~/package/ $ cmake -S . -B build -G "MinGW Makefiles" # From directory with CMakeLists.txt
~/package/ $ make -C build
~/package/ $ build\MyExample
```

Once cmake build has been called, we can edit files and directly run them using
```
~/package/ $ make -C build && build\MyExample
```

## Tutorial


```cmake
##### ------------------- BASICS ------------------- #####

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
```

## Root Directory Project

Example [implementation](https://github.com/cmd05/Practice-and-Principles-CPP-Solutions/tree/master/cmake-tutorial/simple-root-project)

```
Project:
    CMakeLists.txt                                            
    simple_example.cpp                                                
    simple_lib.cpp                                               
    simple_lib.hpp 
```

## Single-Library Project

Example implementation of [single library project](https://github.com/cmd05/Practice-and-Principles-CPP-Solutions/tree/master/cmake-tutorial/single-lib-project)

```
C: simple-lib-project

│   .gitignore                                            
│   CMakeLists.txt                                                  
│   main.cpp                                                             
│                            
├───include                                                
│   └───MyMath                                                   
│           lib.h                                                                                             
└───src
        CMakeLists.txt                                                              
        lib.cpp
```

## Sample Project with External Dependencies
Example [implementation](https://github.com/cmd05/Practice-and-Principles-CPP-Solutions/tree/master/cmake-tutorial/complete-project)

```
C: complete-project
│   .gitignore
│   CMakeLists.txt                                                
│   README.md 
│             
├───apps      
│       app.cpp                                            
│       CMakeLists.txt                                               
│             
├───cmake     
│       add_FetchContent_MakeAvailable.cmake                                        
│       FindBoost.cmake                  
│       FindDoxygen.cmake                                       
│             
├───docs      
│       CMakeLists.txt                                     
│             
├───include   
│   └───modern
│           lib.hpp                                        
│             
├───src       
│       CMakeLists.txt                                           
│       lib.cpp                                        
│             
└───tests     
        CMakeLists.txt                                                       
        testlib.cpp
```

## Multi-Library Project

Example of multi-library [cmake-project](https://github.com/Jamagas/CMake)

```
Foo
 ├── include
 │   └── Foo
 │       ├── Foo.h
 │       └── ...
 ├── src
 │   ├── Foo.cpp
 │   └── ...
 ├── test
 │   └── ...
 └── libs
     ├── A
     │   ├── include
     │   │   └── A
     │   │       ├── A.h
     │   │       └── ...
     │   ├── src
     │   │   ├── A.cpp
     │   │   └── ...
     │   └── test
     │       └── ...
     └── B
         ├── include
         │   └── B
         │       ├── B.h
         │       └── ...
         ├── src
         │   ├── B.cpp
         │   └── ...
         └── test
             └── ...
```