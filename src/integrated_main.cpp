#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <chrono>
#include <limits>

// Include all required headers
#include "dsa/Array.hpp"
#include "dsa/LinkedList.hpp"
#include "dsa/Stack.hpp"
#include "dsa/Queue.hpp"
#include "dsa/Tree.hpp"
#include "dsa/Graph.hpp"
#include "dsa/HashMap.hpp"

// Forward declarations of all external main functions
// These will be implemented as wrappers around the actual functionality
namespace examples {
    int basic();
    int advanced();
}

namespace tests {
    int test_Array();
    int test_LinkedList();
    int test_Stack();
    int test_Queue();
    int test_Tree();
    int test_Graph();
    int test_HashMap();
}

namespace benchmarks {
    int run_all();
    int run_comparisons();
}

// Forward declarations for comparison benchmarks functions
void runComparisons();

// Main menu function
void displayMenu() {
    std::cout << "\n===== DSA Library Integrated Program =====\n";
    std::cout << "1. Run Basic Example\n";
    std::cout << "2. Run Advanced Example\n";
    std::cout << "3. Run Array Tests\n";
    std::cout << "4. Run LinkedList Tests\n";
    std::cout << "5. Run Stack Tests\n";
    std::cout << "6. Run Queue Tests\n";
    std::cout << "7. Run Tree Tests\n";
    std::cout << "8. Run Graph Tests\n";
    std::cout << "9. Run HashMap Tests\n";
    std::cout << "10. Run All Benchmarks\n";
    std::cout << "11. Compare DSA vs STL Performance\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

// Example implementations
namespace examples {
    int basic() {
        std::cout << "\n===== Running Basic Example =====\n";
        // Include code from example_basic.cpp main() here
        std::cout << "Example Basic: Using Array, LinkedList, Stack and Queue\n";
        
        // Array
        dsa::DynamicArray<int> array;
        for (int i = 0; i < 5; i++)
            array.push_back(i);
        std::cout << "Array: ";
        for (size_t i = 0; i < array.size(); i++)
            std::cout << array[i] << " ";
        std::cout << "\n";
        
        // LinkedList
        dsa::LinkedList<int> list;
        for (int i = 0; i < 5; i++)
            list.push_back(i);
        std::cout << "LinkedList: ";
        for (auto it = list.begin(); it != list.end(); ++it)
            std::cout << *it << " ";
        std::cout << "\n";
        
        // Stack
        dsa::Stack<int> stack;
        for (int i = 0; i < 5; i++)
            stack.push(i);
        std::cout << "Stack (top to bottom): ";
        while (!stack.empty()) {
            std::cout << stack.top() << " ";
            stack.pop();
        }
        std::cout << "\n";
        
        // Queue
        dsa::Queue<int> queue;
        for (int i = 0; i < 5; i++)
            queue.enqueue(i);
        std::cout << "Queue (front to back): ";
        while (!queue.empty()) {
            std::cout << queue.front() << " ";
            queue.dequeue();
        }
        std::cout << "\n";
        
        return 0;
    }
    
    int advanced() {
        std::cout << "\n===== Running Advanced Example =====\n";
        // Include code from example_advanced.cpp main() here
        std::cout << "Example Advanced: Using BinarySearchTree, Graph, and HashMap\n";
        
        // Binary Search Tree
        dsa::BinarySearchTree<int> bst;
        bst.insert(50);
        bst.insert(30);
        bst.insert(70);
        bst.insert(20);
        bst.insert(40);
        bst.insert(60);
        bst.insert(80);
        std::cout << "BST In-Order Traversal: ";
        bst.inOrderTraversal();
        std::cout << "\n";
        
        // Graph
        dsa::Graph<int> graph;
        int v0 = graph.addVertex(0);
        int v1 = graph.addVertex(1);
        int v2 = graph.addVertex(2);
        int v3 = graph.addVertex(3);
        graph.addEdge(v0, v1);
        graph.addEdge(v0, v2);
        graph.addEdge(v1, v2);
        graph.addEdge(v2, v3);
        std::cout << "Graph:\n";
        graph.printGraph();
        
        // Hash Map
        dsa::HashMap<std::string, int> hashmap;
        hashmap.put("alpha", 1);
        hashmap.put("beta", 2);
        hashmap.put("gamma", 3);
        int value;
        if (hashmap.get("beta", value))
            std::cout << "HashMap: beta -> " << value << "\n";
        
        return 0;
    }
}

// Test implementations - these will call the actual test functions
namespace tests {
    // Simple test function to display Array class functions
    int test_Array() {
        std::cout << "\n===== Running Array Tests =====\n";
        
        dsa::DynamicArray<int> array;
        
        // Test push_back and size
        std::cout << "Testing push_back and size...\n";
        for (int i = 0; i < 10; i++)
            array.push_back(i);
        std::cout << "Size after adding 10 elements: " << array.size() << "\n";
        
        // Test operator[]
        std::cout << "Testing operator[]...\n";
        std::cout << "Elements: ";
        for (size_t i = 0; i < array.size(); i++)
            std::cout << array[i] << " ";
        std::cout << "\n";
        
        // No resize test, as it's private
        // Just demonstrate size 
        std::cout << "Size demonstration...\n";
        std::cout << "Current size: " << array.size() << "\n";
        
        // Test clear
        std::cout << "Testing clear...\n";
        array.clear();
        std::cout << "Size after clear: " << array.size() << "\n";
        
        std::cout << "Array tests completed.\n";
        return 0;
    }
    
    int test_LinkedList() {
        std::cout << "\n===== Running LinkedList Tests =====\n";
        
        dsa::LinkedList<int> list;
        
        // Test push_back and size
        std::cout << "Testing push_back and size...\n";
        for (int i = 0; i < 5; i++)
            list.push_back(i);
        std::cout << "List after pushing back 5 elements: ";
        for (auto it = list.begin(); it != list.end(); ++it)
            std::cout << *it << " ";
        std::cout << "\n";
        
        // Test push_front
        std::cout << "Testing push_front...\n";
        list.push_front(10);
        list.push_front(20);
        std::cout << "List after push_front 10 and 20: ";
        for (auto it = list.begin(); it != list.end(); ++it)
            std::cout << *it << " ";
        std::cout << "\n";
        
        // Test element access 
        std::cout << "Testing front access...\n";
        std::cout << "Front element: " << list.front() << "\n";
        
        // Test pop_front
        std::cout << "Testing pop_front...\n";
        list.pop_front();
        std::cout << "List after pop_front: ";
        for (auto it = list.begin(); it != list.end(); ++it)
            std::cout << *it << " ";
        std::cout << "\n";
        
        // Test pop_back
        std::cout << "Testing pop_back...\n";
        list.pop_back();
        std::cout << "List after pop_back: ";
        for (auto it = list.begin(); it != list.end(); ++it)
            std::cout << *it << " ";
        std::cout << "\n";
        
        std::cout << "LinkedList tests completed.\n";
        return 0;
    }
    
    int test_Stack() {
        std::cout << "\n===== Running Stack Tests =====\n";
        
        dsa::Stack<int> stack;
        
        // Test push and empty
        std::cout << "Testing push and empty...\n";
        std::cout << "Is stack empty initially? " << (stack.empty() ? "Yes" : "No") << "\n";
        for (int i = 0; i < 5; i++)
            stack.push(i);
        std::cout << "Is stack empty after pushing 5 elements? " << (stack.empty() ? "Yes" : "No") << "\n";
        
        // Test top and pop
        std::cout << "Testing top and pop...\n";
        std::cout << "Elements from top to bottom: ";
        while (!stack.empty()) {
            std::cout << stack.top() << " ";
            stack.pop();
        }
        std::cout << "\n";
        
        // Test size
        std::cout << "Testing size...\n";
        for (int i = 0; i < 3; i++)
            stack.push(i * 10);
        std::cout << "Size after pushing 3 elements: " << stack.size() << "\n";
        
        std::cout << "Stack tests completed.\n";
        return 0;
    }
    
    int test_Queue() {
        std::cout << "\n===== Running Queue Tests =====\n";
        
        dsa::Queue<int> queue;
        
        // Test enqueue and empty
        std::cout << "Testing enqueue and empty...\n";
        std::cout << "Is queue empty initially? " << (queue.empty() ? "Yes" : "No") << "\n";
        for (int i = 0; i < 5; i++)
            queue.enqueue(i);
        std::cout << "Is queue empty after enqueuing 5 elements? " << (queue.empty() ? "Yes" : "No") << "\n";
        
        // Test front and dequeue
        std::cout << "Testing front and dequeue...\n";
        std::cout << "Elements from front to back: ";
        while (!queue.empty()) {
            std::cout << queue.front() << " ";
            queue.dequeue();
        }
        std::cout << "\n";
        
        // Test size
        std::cout << "Testing size...\n";
        for (int i = 0; i < 3; i++)
            queue.enqueue(i * 10);
        std::cout << "Size after enqueuing 3 elements: " << queue.size() << "\n";
        
        std::cout << "Queue tests completed.\n";
        return 0;
    }
    
    int test_Tree() {
        std::cout << "\n===== Running Tree Tests =====\n";
        
        dsa::BinarySearchTree<int> bst;
        
        // Test insert
        std::cout << "Testing insert...\n";
        bst.insert(50);
        bst.insert(30);
        bst.insert(70);
        bst.insert(20);
        bst.insert(40);
        bst.insert(60);
        bst.insert(80);
        
        // Test traversals
        std::cout << "In-Order Traversal: ";
        bst.inOrderTraversal();
        std::cout << "\n";
        
        // Test search
        std::cout << "Testing search...\n";
        std::cout << "Search for 40: " << (bst.search(40) ? "Found" : "Not Found") << "\n";
        std::cout << "Search for 90: " << (bst.search(90) ? "Found" : "Not Found") << "\n";
        
        // Test remove
        std::cout << "Testing remove...\n";
        bst.remove(30);
        std::cout << "In-Order Traversal after removing 30: ";
        bst.inOrderTraversal();
        std::cout << "\n";
        
        std::cout << "Tree tests completed.\n";
        return 0;
    }
    
    int test_Graph() {
        std::cout << "\n===== Running Graph Tests =====\n";
        
        dsa::Graph<int> graph;
        
        // Test addVertex
        std::cout << "Testing addVertex...\n";
        int v0 = graph.addVertex(0);
        int v1 = graph.addVertex(1);
        int v2 = graph.addVertex(2);
        int v3 = graph.addVertex(3);
        
        // Test addEdge
        std::cout << "Testing addEdge...\n";
        graph.addEdge(v0, v1);
        graph.addEdge(v0, v2);
        graph.addEdge(v1, v2);
        graph.addEdge(v2, v3);
        
        // Test printGraph
        std::cout << "Graph structure:\n";
        graph.printGraph();
        
        // Test BFS and DFS
        std::cout << "BFS starting from vertex 0: ";
        graph.BFS(v0);
        std::cout << "DFS starting from vertex 0: ";
        graph.DFS(v0);
        
        std::cout << "Graph tests completed.\n";
        return 0;
    }
    
    int test_HashMap() {
        std::cout << "\n===== Running HashMap Tests =====\n";
        
        dsa::HashMap<std::string, int> hashmap;
        
        // Test put
        std::cout << "Testing put...\n";
        hashmap.put("alpha", 1);
        hashmap.put("beta", 2);
        hashmap.put("gamma", 3);
        hashmap.put("delta", 4);
        
        // Test get
        std::cout << "Testing get...\n";
        int value;
        if (hashmap.get("beta", value))
            std::cout << "beta -> " << value << "\n";
        if (hashmap.get("gamma", value))
            std::cout << "gamma -> " << value << "\n";
        
        // Test contains key with get()
        std::cout << "Testing contains key with get()...\n";
        int dummy;
        std::cout << "Contains key 'alpha': " << (hashmap.get("alpha", dummy) ? "Yes" : "No") << "\n";
        std::cout << "Contains key 'epsilon': " << (hashmap.get("epsilon", dummy) ? "Yes" : "No") << "\n";
        
        // Test remove
        std::cout << "Testing remove...\n";
        hashmap.remove("beta");
        std::cout << "Contains key 'beta' after removal: " << (hashmap.get("beta", dummy) ? "Yes" : "No") << "\n";
        
        std::cout << "HashMap tests completed.\n";
        return 0;
    }
}

// Benchmark implementation - this would normally call Google Benchmark
namespace benchmarks {
    int run_all() {
        std::cout << "\n===== Running All Benchmarks =====\n";
        std::cout << "This would normally run the benchmark_all executable.\n";
        std::cout << "For demonstration, we'll show some simple performance metrics:\n\n";
        
        // Simple Array benchmark
        {
            std::cout << "Array push_back benchmark:\n";
            dsa::DynamicArray<int> array;
            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < 100000; i++) {
                array.push_back(i);
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> duration = end - start;
            std::cout << "Time to push_back 100,000 elements: " << duration.count() << " ms\n\n";
        }
        
        // Simple LinkedList benchmark
        {
            std::cout << "LinkedList push_back benchmark:\n";
            dsa::LinkedList<int> list;
            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < 10000; i++) {
                list.push_back(i);
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> duration = end - start;
            std::cout << "Time to push_back 10,000 elements: " << duration.count() << " ms\n\n";
        }
        
        // Simple Stack benchmark
        {
            std::cout << "Stack push benchmark:\n";
            dsa::Stack<int> stack;
            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < 100000; i++) {
                stack.push(i);
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> duration = end - start;
            std::cout << "Time to push 100,000 elements: " << duration.count() << " ms\n\n";
        }
        
        std::cout << "To run the full benchmarks with Google Benchmark:\n";
        std::cout << "cd build/benchmarks && ./benchmark_all\n";
        
        return 0;
    }
    
    // Add comparison benchmarks
    int run_comparisons() {
        std::cout << "\n===== Running STL Comparison Benchmarks =====\n";
        runComparisons();
        return 0;
    }
}

int main() {
    std::map<int, std::function<int()>> menuOptions = {
        {1, examples::basic},
        {2, examples::advanced},
        {3, tests::test_Array},
        {4, tests::test_LinkedList},
        {5, tests::test_Stack},
        {6, tests::test_Queue},
        {7, tests::test_Tree},
        {8, tests::test_Graph},
        {9, tests::test_HashMap},
        {10, benchmarks::run_all},
        {11, benchmarks::run_comparisons}
    };
    
    int choice;
    
    do {
        displayMenu();
        std::cin >> choice;
        
        if (choice == 0) {
            std::cout << "Exiting program. Goodbye!\n";
            break;
        }
        
        auto it = menuOptions.find(choice);
        if (it != menuOptions.end()) {
            it->second(); // Execute the selected function
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
        
        std::cout << "\nPress Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        
    } while (true);
    
    return 0;
} 