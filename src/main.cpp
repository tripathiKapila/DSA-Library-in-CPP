/**
 * @file main.cpp
 * @brief Main application for the DSALibraryProject.
 *
 * Demonstrates the usage of various data structures and the Logger.
 */

 #include <iostream>
 #include "dsa/Array.hpp"
 #include "dsa/LinkedList.hpp"
 #include "dsa/Stack.hpp"
 #include "dsa/Queue.hpp"
 #include "dsa/Tree.hpp"
 #include "dsa/Graph.hpp"
 #include "dsa/HashMap.hpp"
 #include "dsa/Logger.hpp"
 
 using namespace dsa;
 
 int main() {
     // Log application start
     Logger::instance().log(Logger::LogLevel::INFO, "Starting DSALibraryProject main application.");
 
     std::cout << "Testing DynamicArray:" << std::endl;
     DynamicArray<int> arr;
     for (int i = 0; i < 10; ++i)
         arr.push_back(i);
     for (std::size_t i = 0; i < arr.size(); ++i)
         std::cout << arr[i] << " ";
     std::cout << "\n\n";
 
     std::cout << "Testing LinkedList:" << std::endl;
     LinkedList<int> list;
     list.push_back(1);
     list.push_back(2);
     list.push_back(3);
     for (auto val : list) {
         std::cout << val << " ";
     }
     std::cout << "\n\n";
 
     std::cout << "Testing Stack:" << std::endl;
     Stack<int> stack;
     stack.push(10);
     stack.push(20);
     stack.push(30);
     while (!stack.empty()) {
         std::cout << stack.top() << " ";
         stack.pop();
     }
     std::cout << "\n\n";
 
     std::cout << "Testing Queue:" << std::endl;
     Queue<int> queue;
     queue.enqueue(100);
     queue.enqueue(200);
     queue.enqueue(300);
     while (!queue.empty()) {
         std::cout << queue.front() << " ";
         queue.dequeue();
     }
     std::cout << "\n\n";
 
     std::cout << "Testing BinarySearchTree:" << std::endl;
     BinarySearchTree<int> bst;
     bst.insert(50);
     bst.insert(30);
     bst.insert(70);
     bst.insert(20);
     bst.insert(40);
     bst.insert(60);
     bst.insert(80);
     bst.inOrderTraversal();
     std::cout << "\n";
     std::cout << "Search 40: " << (bst.search(40) ? "Found" : "Not Found") << "\n";
     std::cout << "Search 100: " << (bst.search(100) ? "Found" : "Not Found") << "\n\n";
 
     std::cout << "Testing Graph:" << std::endl;
     Graph graph(5);
     graph.addEdge(0, 1);
     graph.addEdge(0, 4);
     graph.addEdge(1, 2);
     graph.addEdge(1, 3);
     graph.addEdge(1, 4);
     graph.addEdge(2, 3);
     graph.addEdge(3, 4);
     graph.printGraph();
     std::cout << "\nBFS from vertex 0: ";
     graph.BFS(0);
     std::cout << "DFS from vertex 0: ";
     graph.DFS(0);
     std::cout << "\n";
 
     std::cout << "Testing HashMap:" << std::endl;
     HashMap<std::string, int> hashmap;
     hashmap.put("apple", 1);
     hashmap.put("banana", 2);
     hashmap.put("cherry", 3);
     int value;
     if (hashmap.get("banana", value))
         std::cout << "banana: " << value << "\n";
     hashmap.remove("banana");
     if (!hashmap.get("banana", value))
         std::cout << "banana removed\n";
 
     // Log application end
     Logger::instance().log(Logger::LogLevel::INFO, "Finished DSALibraryProject main application.");
     return 0;
 }
 