/**
 * @file Graph.hpp
 * @brief Declares a graph using an adjacency list representation.
 */

 #ifndef DSA_GRAPH_HPP
 #define DSA_GRAPH_HPP
 
 #include <vector>
 #include <list>
 #include <iostream>
 #include <queue>
 #include <stack>
 
 namespace dsa {
 
 /**
  * @class Graph
  * @brief A graph implemented with an adjacency list.
  *
  * Provides methods to add edges and traverse the graph using BFS and DFS.
  */
 class Graph {
 public:
     /**
      * @brief Constructs a graph with a specified number of vertices.
      * @param vertices Number of vertices in the graph.
      */
     Graph(int vertices);
 
     /**
      * @brief Adds a directed edge from src to dest.
      *
      * Validates the vertices and prevents duplicate edges.
      *
      * @param src Source vertex.
      * @param dest Destination vertex.
      */
     void addEdge(int src, int dest);
 
     /// Prints the graph.
     void printGraph() const;
 
     /// Performs a Breadth-First Search starting at the given vertex.
     void BFS(int start) const;
 
     /// Performs a Depth-First Search starting at the given vertex.
     void DFS(int start) const;
 
 private:
     int vertices_;  ///< Number of vertices.
     std::vector<std::list<int>> adjList_; ///< Adjacency list.
     /**
      * @brief Checks if an edge exists from src to dest.
      * @param src Source vertex.
      * @param dest Destination vertex.
      * @return True if edge exists, false otherwise.
      */
     bool edgeExists(int src, int dest) const;
 };
 
 } // namespace dsa
 
 #endif // DSA_GRAPH_HPP
 