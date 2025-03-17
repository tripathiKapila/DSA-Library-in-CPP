cmake_minimum_required(VERSION 3.10)
project(DSALibraryExamples)

set(CMAKE_CXX_STANDARD 11)

# Include headers from the top-level "include" directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Build example_basic
add_executable(example_basic example_basic.cpp)

# Build example_advanced
add_executable(example_advanced example_advanced.cpp)

# If you are using a static/shared library for the main project, link it instead:
# target_link_libraries(example_advanced DSALibraryProject)
