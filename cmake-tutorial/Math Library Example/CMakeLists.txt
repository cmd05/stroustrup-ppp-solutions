cmake_minimum_required(VERSION 3.10)

project(Tutorial VERSION 1.0)

# Add lib
add_subdirectory(MathFunctions)

option(USE_MYMATH "Use implementation of math functions" ON)

if(USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
endif()

add_executable(Tutorial tutorial.cpp)

# Add the executable
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

target_include_directories(Tutorial PUBLIC 
                           "${PROJECT_BINARY_DIR}"
                          )

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(TutorialConfig.h.in TutorialConfig.h)