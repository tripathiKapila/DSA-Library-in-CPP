/**
 * @file test_LinkedList.cpp
 * @brief Tests the LinkedList class.
 */

 #include <cassert>
 #include "dsa/LinkedList.hpp"
 
 int main() {
     dsa::LinkedList<int> list;
     list.push_back(10);
     list.push_back(20);
     assert(list.size() == 2);
     assert(list.front() == 10);
     list.pop_front();
     assert(list.front() == 20);
     return 0;
 }
 