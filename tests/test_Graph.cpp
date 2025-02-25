/**
 * @file test_Graph.cpp
 * @brief Tests the Graph class.
 */

 #include "dsa/Graph.hpp"

 int main() {
     dsa::Graph graph(3);
     graph.addEdge(0, 1);
     graph.addEdge(1, 2);
     // Call printGraph to ensure no runtime errors.
     graph.printGraph();
     return 0;
 }
 