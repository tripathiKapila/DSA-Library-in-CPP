cmake_minimum_required(VERSION 3.10)
project(DSALibraryProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing
enable_testing()

# Find Doxygen
find_package(Doxygen REQUIRED)
if(DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    
    # Add custom target for documentation
    add_custom_target(docs
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )
    
    # Add install target for documentation
    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/docs/html
        DESTINATION share/doc/DSALibrary/html
    )
endif()

# Include FetchContent for downloading dependencies
include(FetchContent)

# Google Test
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# RapidCheck
FetchContent_Declare(
    rapidcheck
    GIT_REPOSITORY https://github.com/emil-e/rapidcheck.git
    GIT_TAG master
)

# Configure RapidCheck before making it available
set(RAPIDCHECK_HEADERS_ONLY ON)
set(RAPIDCHECK_ENABLE_GTEST ON)
set(RAPIDCHECK_GTEST_INCLUDE_DIR ${gtest_SOURCE_DIR}/include)
set(RAPIDCHECK_GTEST_LIBRARY gtest)

FetchContent_MakeAvailable(rapidcheck)

# Google Benchmark
FetchContent_Declare(
    benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG v1.7.1
)
FetchContent_MakeAvailable(benchmark)

include_directories(include)

# Main library
add_library(DSALibrary
    src/Array.cpp
    src/LinkedList.cpp
    src/Stack.cpp
    src/Queue.cpp
    src/Tree.cpp
    src/HashMap.cpp
)

# Integrated executable that combines all features
add_executable(DSAIntegrated 
    src/integrated_main.cpp
    src/comparison_benchmarks_fixed.cpp
)
target_link_libraries(DSAIntegrated PRIVATE DSALibrary)

# Include subdirectories for tests and examples
add_subdirectory(tests)
add_subdirectory(examples)
add_subdirectory(benchmarks)

# Installation
install(TARGETS DSALibrary
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)
install(DIRECTORY include/dsa
    DESTINATION include
)
