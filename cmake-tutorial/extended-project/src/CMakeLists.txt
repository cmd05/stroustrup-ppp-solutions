# Create modern_library
set(HEADER_LIST "${PROJECT_SOURCE_DIR}/include/modern/lib.hpp")
add_library(modern_library lib.cpp ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(modern_library PUBLIC ../include)

# This depends on (header only) boost
# target_link_libraries(modern_library PRIVATE Boost::boost)

# All users of this library will need at least C++11
target_compile_features(modern_library PUBLIC cxx_std_11)

# IDEs should put the headers in a nice place
source_group (
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST}
)