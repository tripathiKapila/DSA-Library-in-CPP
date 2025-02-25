/**
 * @file Graph.cpp
 * @brief Implements the Graph class.
 */

 #include "dsa/Graph.hpp"

 namespace dsa {
 
 Graph::Graph(int vertices)
     : vertices_(vertices), adjList_(vertices) {}
 
 bool Graph::edgeExists(int src, int dest) const {
     for (int v : adjList_[src])
         if (v == dest)
             return true;
     return false;
 }
 
 void Graph::addEdge(int src, int dest) {
     if (src >= 0 && src < vertices_ && dest >= 0 && dest < vertices_) {
         if (!edgeExists(src, dest))
             adjList_[src].push_back(dest);
         // For an undirected graph, uncomment:
         /*
         if (!edgeExists(dest, src))
             adjList_[dest].push_back(src);
         */
     }
 }
 
 void Graph::printGraph() const {
     for (int i = 0; i < vertices_; ++i) {
         std::cout << "Vertex " << i << ":";
         for (int v : adjList_[i])
             std::cout << " -> " << v;
         std::cout << std::endl;
     }
 }
 
 void Graph::BFS(int start) const {
     if (start < 0 || start >= vertices_)
         return;
     std::vector<bool> visited(vertices_, false);
     std::queue<int> q;
     visited[start] = true;
     q.push(start);
     while (!q.empty()) {
         int vertex = q.front(); q.pop();
         std::cout << vertex << " ";
         for (int adj : adjList_[vertex])
             if (!visited[adj]) {
                 visited[adj] = true;
                 q.push(adj);
             }
     }
     std::cout << std::endl;
 }
 
 void Graph::DFS(int start) const {
     if (start < 0 || start >= vertices_)
         return;
     std::vector<bool> visited(vertices_, false);
     std::stack<int> s;
     s.push(start);
     while (!s.empty()) {
         int vertex = s.top(); s.pop();
         if (!visited[vertex]) {
             visited[vertex] = true;
             std::cout << vertex << " ";
             for (auto it = adjList_[vertex].rbegin(); it != adjList_[vertex].rend(); ++it)
                 if (!visited[*it])
                     s.push(*it);
         }
     }
     std::cout << std::endl;
 }
 
 } // namespace dsa
 