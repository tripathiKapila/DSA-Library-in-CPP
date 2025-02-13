#ifndef DSA_GRAPH_HPP
#define DSA_GRAPH_HPP

#include <vector>
#include <list>
#include <iostream>

namespace dsa {

class Graph {
public:
    // Constructor
    Graph(int vertices);

    // Add an edge from 'src' to 'dest'
    void addEdge(int src, int dest);

    // Print the adjacency list for each vertex
    void printGraph() const;

private:
    int vertices_;
    std::vector<std::list<int>> adjList_;
};

} // namespace dsa

#endif // DSA_GRAPH_HPP
