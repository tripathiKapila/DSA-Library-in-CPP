cmake_minimum_required(VERSION 3.10)
project(DSALibraryProject)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

# Main executable
add_executable(DSALibraryProject
    src/main.cpp
    src/Array.cpp
    src/LinkedList.cpp
    src/Stack.cpp
    src/Queue.cpp
    src/Tree.cpp
    src/Graph.cpp
    src/HashMap.cpp
)

# Include subdirectories for tests and examples
add_subdirectory(tests)
add_subdirectory(examples)
