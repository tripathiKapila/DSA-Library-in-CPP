#include <iostream>
#include "dsa/Array.hpp"
#include "dsa/LinkedList.hpp"
#include "dsa/Stack.hpp"
#include "dsa/Queue.hpp"
#include "dsa/Tree.hpp"
#include "dsa/Graph.hpp"
#include "dsa/HashMap.hpp"

using namespace dsa;

int main() {
    // --- Test DynamicArray ---
    std::cout << "Testing DynamicArray:" << std::endl;
    DynamicArray<int> arr;
    for (int i = 0; i < 10; ++i)
        arr.push_back(i);
    for (std::size_t i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n\n";

    // --- Test LinkedList ---
    std::cout << "Testing LinkedList:" << std::endl;
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    while (!list.empty()) {
        std::cout << list.front() << " ";
        list.pop_front();
    }
    std::cout << "\n\n";

    // --- Test Stack ---
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

    // --- Test Queue ---
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

    // --- Test BinarySearchTree ---
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

    // --- Test Graph ---
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
    std::cout << "\n";

    // --- Test HashMap ---
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

    return 0;
}
