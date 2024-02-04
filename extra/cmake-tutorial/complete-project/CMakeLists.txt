# --------------------------------------------- #

cmake_minimum_required(VERSION 3.11...3.23)

project(ModernCMakeExample
	    VERSION 0.1.0
        DESCRIPTION "An example project with CMake"
		LANGUAGES CXX C)

# --------------------------------------------- #

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here

  # --------------------------------------------- #

  # Let's ensure -std=c++xx instead of -std=g++xx
  set(CMAKE_CXX_EXTENSIONS OFF)

  # Let's nicely support folders in IDEs
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  # --------------------------------------------- #





  # --------------------------------------------- #

  # Testing only available if this is the main app
  # Note this needs to be done in the main CMakeLists
  # since it calls enable_testing, which must be in the
  # main CMakeLists.
  include(CTest)

  # --------------------------------------------- #






  # --------------------------------------------- #
  
  # Docs only available if this is the main app
  find_package(Doxygen)
  if(Doxygen_FOUND)
    add_subdirectory(docs)
  else()
    message(STATUS "Doxygen not found, not building docs")
  endif()
  
  # --------------------------------------------- #

endif()



# --------------------------------------------- #

# FetchContent added in CMake 3.11, downloads during the configure step
include(FetchContent)
# FetchContent_MakeAvailable was not added until CMake 3.14; use our shim
if(${CMAKE_VERSION} VERSION_LESS 3.14)
  include(cmake/add_FetchContent_MakeAvailable.cmake)
endif()

# --------------------------------------------- #






# --------------------------------------------- #


set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "${BOOST_PATH}")

string(CONCAT BOOST_LIB_PATH "{BOOST_PATH}" "/libs")
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${BOOST_LIB_PATH}")

find_package(Boost)
IF (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    add_definitions( "-DHAS_BOOST" )
else()
    message( FATAL_ERROR "Boost not found" )
endif()

# --------------------------------------------- #





# --------------------------------------------- #

FetchContent_Declare(
  fmtlib
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 5.3.0)
FetchContent_MakeAvailable(fmtlib)
# Adds fmt::fmt

# --------------------------------------------- #






# --------------------------------------------- #

# The compiled library code is here
add_subdirectory(src)

# The executable code is here
add_subdirectory(apps)

# --------------------------------------------- #






# --------------------------------------------- #

# Testing only available if this is the main app
# Emergency override MODERN_CMAKE_BUILD_TESTING provided as well
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING)
   AND BUILD_TESTING)
  add_subdirectory(tests)
endif()

# --------------------------------------------- #
