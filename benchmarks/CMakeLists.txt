cmake_minimum_required(VERSION 3.10)
project(DSALibraryBenchmarks)

set(CMAKE_CXX_STANDARD 17)

# Include headers from the top-level "include" directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Create benchmark executable
add_executable(benchmark_all benchmark_all.cpp)

# Link benchmark executable with the main library and Google Benchmark
target_link_libraries(benchmark_all PRIVATE DSALibrary benchmark::benchmark) 