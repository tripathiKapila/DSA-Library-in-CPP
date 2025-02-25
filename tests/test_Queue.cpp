/**
 * @file test_Queue.cpp
 * @brief Tests the Queue class.
 */

 #include <cassert>
 #include "dsa/Queue.hpp"
 
 int main() {
     dsa::Queue<int> queue;
     queue.enqueue(100);
     queue.enqueue(200);
     assert(queue.front() == 100);
     queue.dequeue();
     assert(queue.front() == 200);
     return 0;
 }
 