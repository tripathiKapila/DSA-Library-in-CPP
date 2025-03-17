#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <random>
#include <iomanip>

#include "dsa/Array.hpp"
#include "dsa/LinkedList.hpp"
#include "dsa/Stack.hpp"
#include "dsa/Queue.hpp"
#include "dsa/Tree.hpp"
#include "dsa/HashMap.hpp"
#include "dsa/Graph.hpp"

// Helper function to measure execution time
template<typename Func>
double measureTime(Func func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::milli>(end - start).count();
}

// Array vs Vector benchmark
void compareArrayAndVector(int size) {
    std::cout << "=== DynamicArray vs std::vector (size = " << size << ") ===\n";
    
    // Push Back Operation
    double dsa_time = measureTime([size]() {
        dsa::DynamicArray<int> array;
        for (int i = 0; i < size; i++) {
            array.push_back(i);
        }
    });
    
    double stl_time = measureTime([size]() {
        std::vector<int> vector;
        for (int i = 0; i < size; i++) {
            vector.push_back(i);
        }
    });
    
    std::cout << "Push back operation:\n";
    std::cout << "  DynamicArray: " << std::fixed << std::setprecision(3) << dsa_time << " ms\n";
    std::cout << "  std::vector:  " << std::fixed << std::setprecision(3) << stl_time << " ms\n";
    std::cout << "  Ratio (DSA/STL): " << std::fixed << std::setprecision(2) << dsa_time / stl_time << "x\n\n";
    
    // Random Access Operation
    dsa::DynamicArray<int> dsa_array;
    std::vector<int> stl_vector;
    
    // Fill both containers
    for (int i = 0; i < size; i++) {
        dsa_array.push_back(i);
        stl_vector.push_back(i);
    }
    
    // Generate random indices
    std::vector<int> indices(size);
    for (int i = 0; i < size; i++) {
        indices[i] = rand() % size;
    }
    
    // Random Access
    volatile int sum1 = 0; // volatile to prevent optimization
    dsa_time = measureTime([&]() {
        for (int i = 0; i < size; i++) {
            sum1 += dsa_array[indices[i]];
        }
    });
    
    volatile int sum2 = 0;
    stl_time = measureTime([&]() {
        for (int i = 0; i < size; i++) {
            sum2 += stl_vector[indices[i]];
        }
    });
    
    std::cout << "Random access operation:\n";
    std::cout << "  DynamicArray: " << std::fixed << std::setprecision(3) << dsa_time << " ms\n";
    std::cout << "  std::vector:  " << std::fixed << std::setprecision(3) << stl_time << " ms\n";
    std::cout << "  Ratio (DSA/STL): " << std::fixed << std::setprecision(2) << dsa_time / stl_time << "x\n\n";
}

// LinkedList vs list benchmark
void compareLinkedListAndList(int size) {
    std::cout << "=== LinkedList vs std::list (size = " << size << ") ===\n";
    
    // Push Back Operation
    double dsa_time = measureTime([size]() {
        dsa::LinkedList<int> list;
        for (int i = 0; i < size; i++) {
            list.push_back(i);
        }
    });
    
    double stl_time = measureTime([size]() {
        std::list<int> list;
        for (int i = 0; i < size; i++) {
            list.push_back(i);
        }
    });
    
    std::cout << "Push back operation:\n";
    std::cout << "  LinkedList: " << std::fixed << std::setprecision(3) << dsa_time << " ms\n";
    std::cout << "  std::list:  " << std::fixed << std::setprecision(3) << stl_time << " ms\n";
    std::cout << "  Ratio (DSA/STL): " << std::fixed << std::setprecision(2) << dsa_time / stl_time << "x\n\n";
    
    // Push Front Operation
    dsa_time = measureTime([size]() {
        dsa::LinkedList<int> list;
        for (int i = 0; i < size; i++) {
            list.push_front(i);
        }
    });
    
    stl_time = measureTime([size]() {
        std::list<int> list;
        for (int i = 0; i < size; i++) {
            list.push_front(i);
        }
    });
    
    std::cout << "Push front operation:\n";
    std::cout << "  LinkedList: " << std::fixed << std::setprecision(3) << dsa_time << " ms\n";
    std::cout << "  std::list:  " << std::fixed << std::setprecision(3) << stl_time << " ms\n";
    std::cout << "  Ratio (DSA/STL): " << std::fixed << std::setprecision(2) << dsa_time / stl_time << "x\n\n";
}

// Stack benchmark
void compareStackAndStdStack(int size) {
    std::cout << "=== Stack vs std::stack (size = " << size << ") ===\n";
    
    // Push Operation
    double dsa_time = measureTime([size]() {
        dsa::Stack<int> stack;
        for (int i = 0; i < size; i++) {
            stack.push(i);
        }
    });
    
    double stl_time = measureTime([size]() {
        std::stack<int> stack;
        for (int i = 0; i < size; i++) {
            stack.push(i);
        }
    });
    
    std::cout << "Push operation:\n";
    std::cout << "  Stack:      " << std::fixed << std::setprecision(3) << dsa_time << " ms\n";
    std::cout << "  std::stack: " << std::fixed << std::setprecision(3) << stl_time << " ms\n";
    std::cout << "  Ratio (DSA/STL): " << std::fixed << std::setprecision(2) << dsa_time / stl_time << "x\n\n";
    
    // Push + Pop Operation
    dsa_time = measureTime([size]() {
        dsa::Stack<int> stack;
        for (int i = 0; i < size; i++) {
            stack.push(i);
        }
        while (!stack.empty()) {
            stack.pop();
        }
    });
    
    stl_time = measureTime([size]() {
        std::stack<int> stack;
        for (int i = 0; i < size; i++) {
            stack.push(i);
        }
        while (!stack.empty()) {
            stack.pop();
        }
    });
    
    std::cout << "Push + Pop operations (LIFO access pattern):\n";
    std::cout << "  Stack:      " << std::fixed << std::setprecision(3) << dsa_time << " ms\n";
    std::cout << "  std::stack: " << std::fixed << std::setprecision(3) << stl_time << " ms\n";
    std::cout << "  Ratio (DSA/STL): " << std::fixed << std::setprecision(2) << dsa_time / stl_time << "x\n\n";
}

// Queue benchmark
void compareQueueAndStdQueue(int size) {
    std::cout << "=== Queue vs std::queue (size = " << size << ") ===\n";
    
    // Enqueue Operation
    double dsa_time = measureTime([size]() {
        dsa::Queue<int> queue;
        for (int i = 0; i < size; i++) {
            queue.enqueue(i);
        }
    });
    
    double stl_time = measureTime([size]() {
        std::queue<int> queue;
        for (int i = 0; i < size; i++) {
            queue.push(i);
        }
    });
    
    std::cout << "Enqueue operation:\n";
    std::cout << "  Queue:      " << std::fixed << std::setprecision(3) << dsa_time << " ms\n";
    std::cout << "  std::queue: " << std::fixed << std::setprecision(3) << stl_time << " ms\n";
    std::cout << "  Ratio (DSA/STL): " << std::fixed << std::setprecision(2) << dsa_time / stl_time << "x\n\n";
    
    // Enqueue + Dequeue Operation
    dsa_time = measureTime([size]() {
        dsa::Queue<int> queue;
        for (int i = 0; i < size; i++) {
            queue.enqueue(i);
        }
        while (!queue.empty()) {
            queue.dequeue();
        }
    });
    
    stl_time = measureTime([size]() {
        std::queue<int> queue;
        for (int i = 0; i < size; i++) {
            queue.push(i);
        }
        while (!queue.empty()) {
            queue.pop();
        }
    });
    
    std::cout << "Enqueue + Dequeue operations (FIFO access pattern):\n";
    std::cout << "  Queue:      " << std::fixed << std::setprecision(3) << dsa_time << " ms\n";
    std::cout << "  std::queue: " << std::fixed << std::setprecision(3) << stl_time << " ms\n";
    std::cout << "  Ratio (DSA/STL): " << std::fixed << std::setprecision(2) << dsa_time / stl_time << "x\n\n";
}

// BinarySearchTree vs map benchmark
void compareTreeAndMap(int size) {
    std::cout << "=== BinarySearchTree vs std::map (size = " << size << ") ===\n";
    
    // Random numbers for insertion
    std::vector<int> values(size);
    for (int i = 0; i < size; i++) {
        values[i] = rand() % (size * 10);
    }
    
    // Insert Operation
    double dsa_time = measureTime([&]() {
        dsa::BinarySearchTree<int> tree;
        for (int i = 0; i < size; i++) {
            tree.insert(values[i]);
        }
    });
    
    double stl_time = measureTime([&]() {
        std::map<int, int> map;
        for (int i = 0; i < size; i++) {
            map[values[i]] = i;
        }
    });
    
    std::cout << "Insert operation:\n";
    std::cout << "  BinarySearchTree: " << std::fixed << std::setprecision(3) << dsa_time << " ms\n";
    std::cout << "  std::map:         " << std::fixed << std::setprecision(3) << stl_time << " ms\n";
    std::cout << "  Ratio (DSA/STL): " << std::fixed << std::setprecision(2) << dsa_time / stl_time << "x\n\n";
    
    // Search Operation
    // First create populated structures
    dsa::BinarySearchTree<int> dsa_tree;
    std::map<int, int> stl_map;
    
    for (int i = 0; i < size; i++) {
        dsa_tree.insert(values[i]);
        stl_map[values[i]] = i;
    }
    
    // Now benchmark search operations
    dsa_time = measureTime([&]() {
        for (int i = 0; i < size; i++) {
            volatile bool found = dsa_tree.search(values[i % size]);
        }
    });
    
    stl_time = measureTime([&]() {
        for (int i = 0; i < size; i++) {
            volatile auto it = stl_map.find(values[i % size]);
        }
    });
    
    std::cout << "Search operation:\n";
    std::cout << "  BinarySearchTree: " << std::fixed << std::setprecision(3) << dsa_time << " ms\n";
    std::cout << "  std::map:         " << std::fixed << std::setprecision(3) << stl_time << " ms\n";
    std::cout << "  Ratio (DSA/STL): " << std::fixed << std::setprecision(2) << dsa_time / stl_time << "x\n\n";
}

// HashMap vs unordered_map benchmark
void compareHashMapAndUnorderedMap(int size) {
    std::cout << "=== HashMap vs std::unordered_map (size = " << size << ") ===\n";
    
    // Generate random strings for keys
    std::vector<std::string> keys(size);
    for (int i = 0; i < size; i++) {
        std::string key = "key" + std::to_string(i);
        keys[i] = key;
    }
    
    // Put/Insert Operation
    double dsa_time = measureTime([&]() {
        dsa::HashMap<std::string, int> hashmap;
        for (int i = 0; i < size; i++) {
            hashmap.put(keys[i], i);
        }
    });
    
    double stl_time = measureTime([&]() {
        std::unordered_map<std::string, int> hashmap;
        for (int i = 0; i < size; i++) {
            hashmap[keys[i]] = i;
        }
    });
    
    std::cout << "Insert operation:\n";
    std::cout << "  HashMap:            " << std::fixed << std::setprecision(3) << dsa_time << " ms\n";
    std::cout << "  std::unordered_map: " << std::fixed << std::setprecision(3) << stl_time << " ms\n";
    std::cout << "  Ratio (DSA/STL): " << std::fixed << std::setprecision(2) << dsa_time / stl_time << "x\n\n";
    
    // Get/Find Operation
    // First create populated structures
    dsa::HashMap<std::string, int> dsa_map;
    std::unordered_map<std::string, int> stl_map;
    
    for (int i = 0; i < size; i++) {
        dsa_map.put(keys[i], i);
        stl_map[keys[i]] = i;
    }
    
    // Now benchmark get/find operations
    dsa_time = measureTime([&]() {
        int value;
        for (int i = 0; i < size; i++) {
            dsa_map.get(keys[i % size], value);
        }
    });
    
    stl_time = measureTime([&]() {
        for (int i = 0; i < size; i++) {
            volatile auto it = stl_map.find(keys[i % size]);
        }
    });
    
    std::cout << "Lookup operation:\n";
    std::cout << "  HashMap:            " << std::fixed << std::setprecision(3) << dsa_time << " ms\n";
    std::cout << "  std::unordered_map: " << std::fixed << std::setprecision(3) << stl_time << " ms\n";
    std::cout << "  Ratio (DSA/STL): " << std::fixed << std::setprecision(2) << dsa_time / stl_time << "x\n\n";
}

// Main function to run all comparisons
void runComparisons() {
    // Seed random number generator
    srand(static_cast<unsigned int>(time(nullptr)));
    
    std::cout << "\n==========================================\n";
    std::cout << "COMPARING CUSTOM DSA vs STL CONTAINERS\n";
    std::cout << "==========================================\n\n";
    
    // Small size (10^3)
    int small_size = 1000;
    std::cout << "SMALL SIZE COMPARISONS (n = " << small_size << ")\n";
    std::cout << "------------------------------------------\n";
    compareArrayAndVector(small_size);
    compareLinkedListAndList(small_size);
    compareStackAndStdStack(small_size);
    compareQueueAndStdQueue(small_size);
    compareTreeAndMap(small_size);
    compareHashMapAndUnorderedMap(small_size);
    
    // Medium size (10^4)
    int medium_size = 10000;
    std::cout << "\nMEDIUM SIZE COMPARISONS (n = " << medium_size << ")\n";
    std::cout << "------------------------------------------\n";
    compareArrayAndVector(medium_size);
    compareLinkedListAndList(medium_size);
    compareStackAndStdStack(medium_size);
    compareQueueAndStdQueue(medium_size);
    compareTreeAndMap(medium_size);
    compareHashMapAndUnorderedMap(medium_size);
    
    // Large size (10^5)
    int large_size = 100000;
    std::cout << "\nLARGE SIZE COMPARISONS (n = " << large_size << ")\n";
    std::cout << "------------------------------------------\n";
    compareArrayAndVector(large_size);
    compareLinkedListAndList(large_size);
    compareStackAndStdStack(large_size);
    compareQueueAndStdQueue(large_size);
    
    // Smaller size for tree and hashmap (these are slower)
    int smaller_size = 50000;
    std::cout << "\nLARGE SIZE COMPARISONS FOR TREE & HASHMAP (n = " << smaller_size << ")\n";
    std::cout << "------------------------------------------\n";
    compareTreeAndMap(smaller_size);
    compareHashMapAndUnorderedMap(smaller_size);
    
    std::cout << "\n==========================================\n";
    std::cout << "BENCHMARK SUMMARY\n";
    std::cout << "==========================================\n";
    std::cout << "DSA Library vs STL Performance Comparison:\n\n";
    std::cout << "These benchmarks compare your custom DSA library\n";
    std::cout << "implementations against the C++ Standard Library.\n\n";
    std::cout << "Key observations:\n";
    std::cout << "- DynamicArray vs std::vector: Shows memory management differences\n";
    std::cout << "- LinkedList vs std::list: Tests link manipulation efficiency\n";
    std::cout << "- Stack/Queue vs STL counterparts: Tests LIFO/FIFO operations\n";
    std::cout << "- BinarySearchTree vs std::map: Compares binary tree implementations\n";
    std::cout << "- HashMap vs std::unordered_map: Tests hashing approach differences\n\n";
    std::cout << "Remember that STL implementations are highly optimized.\n";
    std::cout << "Your implementations prioritize clarity and learning.\n";
}

// Main function (for direct compilation)
int main() {
    runComparisons();
    return 0;
} 