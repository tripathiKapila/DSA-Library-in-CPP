#include "dsa/Graph.hpp"

namespace dsa {

Graph::Graph(int vertices)
    : vertices_(vertices), adjList_(vertices)
{
}

void Graph::addEdge(int src, int dest)
{
    if (src >= 0 && src < vertices_ && dest >= 0 && dest < vertices_) {
        adjList_[src].push_back(dest);
        // For an undirected graph, uncomment the next line:
        // adjList_[dest].push_back(src);
    }
}

void Graph::printGraph() const
{
    for (int i = 0; i < vertices_; ++i) {
        std::cout << "Vertex " << i << ":";
        for (int v : adjList_[i]) {
            std::cout << " -> " << v;
        }
        std::cout << std::endl;
    }
}

} // namespace dsa
