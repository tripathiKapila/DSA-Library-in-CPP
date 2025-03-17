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
  * Provides methods to add vertices, edges, and traverse the graph using BFS and DFS.
  *
  * @tparam T Type of data stored in vertices.
  */
 template<typename T>
 class Graph {
 public:
     /**
      * @brief Default constructor.
      */
     Graph() : vertices_(0) {}

     /**
      * @brief Adds a new vertex with the given value.
      * @param value Value to store in the vertex.
      * @return The index of the new vertex.
      */
     int addVertex(const T& value) {
         values_.push_back(value);
         adjList_.push_back(std::list<int>());
         return vertices_++;
     }
 
     /**
      * @brief Adds a directed edge from src to dest.
      *
      * Validates the vertices and prevents duplicate edges.
      *
      * @param src Source vertex.
      * @param dest Destination vertex.
      */
     void addEdge(int src, int dest) {
         if (src >= 0 && src < vertices_ && dest >= 0 && dest < vertices_) {
             if (!edgeExists(src, dest)) {
                 adjList_[src].push_back(dest);
             }
         }
     }
 
     /// Prints the graph.
     void printGraph() const {
         for (int i = 0; i < vertices_; ++i) {
             std::cout << "Vertex " << i << " (" << values_[i] << "): ";
             for (int dest : adjList_[i]) {
                 std::cout << dest << " ";
             }
             std::cout << std::endl;
         }
     }
 
     /// Performs a Breadth-First Search starting at the given vertex.
     void BFS(int start) const {
         if (start < 0 || start >= vertices_) return;
         
         std::vector<bool> visited(vertices_, false);
         std::queue<int> queue;
         
         visited[start] = true;
         queue.push(start);
         
         while (!queue.empty()) {
             int vertex = queue.front();
             std::cout << values_[vertex] << " ";
             queue.pop();
             
             for (int adjacent : adjList_[vertex]) {
                 if (!visited[adjacent]) {
                     visited[adjacent] = true;
                     queue.push(adjacent);
                 }
             }
         }
         std::cout << std::endl;
     }
 
     /// Performs a Depth-First Search starting at the given vertex.
     void DFS(int start) const {
         if (start < 0 || start >= vertices_) return;
         
         std::vector<bool> visited(vertices_, false);
         DFSUtil(start, visited);
         std::cout << std::endl;
     }
 
 private:
     int vertices_;  ///< Number of vertices.
     std::vector<std::list<int>> adjList_; ///< Adjacency list.
     std::vector<T> values_; ///< Values stored in vertices.

     /**
      * @brief Helper function for DFS.
      * @param vertex Current vertex.
      * @param visited Array of visited flags.
      */
     void DFSUtil(int vertex, std::vector<bool>& visited) const {
         visited[vertex] = true;
         std::cout << values_[vertex] << " ";
         
         for (int adjacent : adjList_[vertex]) {
             if (!visited[adjacent]) {
                 DFSUtil(adjacent, visited);
             }
         }
     }

     /**
      * @brief Checks if an edge exists from src to dest.
      * @param src Source vertex.
      * @param dest Destination vertex.
      * @return True if edge exists, false otherwise.
      */
     bool edgeExists(int src, int dest) const {
         for (int v : adjList_[src]) {
             if (v == dest) return true;
         }
         return false;
     }
 };
 
 } // namespace dsa
 
 #endif // DSA_GRAPH_HPP
 