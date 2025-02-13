#include <iostream>
#include "dsa/Tree.hpp"
#include "dsa/Graph.hpp"
#include "dsa/HashMap.hpp"

int main() {
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
    dsa::Graph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
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
