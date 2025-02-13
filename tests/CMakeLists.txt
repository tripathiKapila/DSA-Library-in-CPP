cmake_minimum_required(VERSION 3.10)
project(DSALibraryTests)

set(CMAKE_CXX_STANDARD 11)

# Include headers from the top-level "include" directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Test for Graph
add_executable(test_Graph test_Graph.cpp)

# Link Graph.cpp to the test
target_sources(test_Graph PRIVATE ${CMAKE_SOURCE_DIR}/src/Graph.cpp)

# If you are using a shared/static library for DSALibraryProject, link it instead
# target_link_libraries(test_Graph DSALibraryProject)
