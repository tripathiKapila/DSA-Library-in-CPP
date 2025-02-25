/**
 * @file Utilities.hpp
 * @brief Provides utility functions for debugging.
 */

 #ifndef DSA_UTILITIES_HPP
 #define DSA_UTILITIES_HPP
 
 #include <iostream>
 #include <chrono>
 #include <string>
 
 namespace dsa {
 
 /**
  * @brief Prints a separator line.
  */
 inline void printSeparator() {
     std::cout << "----------------------------------\n";
 }
 
 /**
  * @brief Prints the elements of a container.
  *
  * Assumes the container supports range-based for loops.
  *
  * @tparam Container Type of the container.
  * @param container The container to print.
  */
 template<typename Container>
 void printVector(const Container& container) {
     for (const auto& elem : container)
         std::cout << elem << " ";
     std::cout << std::endl;
 }
 
 /**
  * @brief Logs a message with a timestamp.
  *
  * (Legacy function, replaced by Logger.)
  *
  * @param message Message to log.
  */
 inline void logMessage(const std::string& message) {
     auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
     std::cout << "[LOG " << std::ctime(&now) << "]: " << message << std::endl;
 }
 
 } // namespace dsa
 
 #endif // DSA_UTILITIES_HPP
 