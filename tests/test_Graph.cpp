/**
 * @file test_Graph.cpp
 * @brief Tests the Graph class.
 */

 #include "dsa/Graph.hpp"

 int main() {
     dsa::Graph<int> graph;
     
     // Add vertices
     int v0 = graph.addVertex(0);
     int v1 = graph.addVertex(1);
     int v2 = graph.addVertex(2);
     
     // Add edges
     graph.addEdge(v0, v1);
     graph.addEdge(v1, v2);
     
     // Call printGraph to ensure no runtime errors.
     graph.printGraph();
     return 0;
 }
 