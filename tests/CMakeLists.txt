cmake_minimum_required(VERSION 3.10)
project(DSALibraryTests)

set(CMAKE_CXX_STANDARD 17)

# Create test executables
add_executable(test_Array test_Array.cpp)
add_executable(test_LinkedList test_LinkedList.cpp)
add_executable(test_Stack test_Stack.cpp)
add_executable(test_Queue test_Queue.cpp)
add_executable(test_Tree test_Tree.cpp)
add_executable(test_Graph test_Graph.cpp)
add_executable(test_HashMap test_HashMap.cpp)

# Set include directories for all test targets
foreach(test_target test_Array test_LinkedList test_Stack test_Queue test_Tree test_Graph test_HashMap)
    target_include_directories(${test_target} PRIVATE 
        ${CMAKE_SOURCE_DIR}/include
        ${rapidcheck_SOURCE_DIR}/include
        ${rapidcheck_BINARY_DIR}/include
        ${gtest_SOURCE_DIR}/include
    )
endforeach()

# Link test executables with the main library
target_link_libraries(test_Array PRIVATE DSALibrary gtest gtest_main rapidcheck)
target_link_libraries(test_LinkedList PRIVATE DSALibrary gtest gtest_main rapidcheck)
target_link_libraries(test_Stack PRIVATE DSALibrary gtest gtest_main rapidcheck)
target_link_libraries(test_Queue PRIVATE DSALibrary gtest gtest_main rapidcheck)
target_link_libraries(test_Tree PRIVATE DSALibrary gtest gtest_main rapidcheck)
target_link_libraries(test_Graph PRIVATE DSALibrary gtest gtest_main rapidcheck)
target_link_libraries(test_HashMap PRIVATE DSALibrary gtest gtest_main rapidcheck)

# Add tests to CTest
add_test(NAME test_Array COMMAND test_Array)
add_test(NAME test_LinkedList COMMAND test_LinkedList)
add_test(NAME test_Stack COMMAND test_Stack)
add_test(NAME test_Queue COMMAND test_Queue)
add_test(NAME test_Tree COMMAND test_Tree)
add_test(NAME test_Graph COMMAND test_Graph)
add_test(NAME test_HashMap COMMAND test_HashMap)
