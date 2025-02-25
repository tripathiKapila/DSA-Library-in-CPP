/**
 * @file Stack.hpp
 * @brief Declares a container-customizable Stack implementation.
 */

 #ifndef DSA_STACK_HPP
 #define DSA_STACK_HPP
 
 #include "LinkedList.hpp"
 #include <stdexcept>
 #include <utility>
 
 namespace dsa {
 
 /**
  * @class Stack
  * @brief A stack implemented using an underlying container.
  *
  * By default, the Stack uses LinkedList as its container, but this can be customized.
  *
  * @tparam T Type of elements.
  * @tparam Container Underlying container type.
  */
 template<typename T, typename Container = LinkedList<T>>
 class Stack {
 public:
     /// Default constructor.
     Stack() = default;
     /// Default destructor.
     ~Stack() = default;
 
     /// Pushes an element onto the stack.
     void push(const T& value) { container_.push_front(value); }
     /// Pushes an element (using move semantics) onto the stack.
     void push(T&& value) { container_.push_front(std::move(value)); }
 
     /// Removes the top element.
     void pop() {
         if (container_.empty())
             throw std::out_of_range("Stack is empty");
         container_.pop_front();
     }
 
     /**
      * @brief Returns the top element.
      * @return Reference to the top element.
      */
     T& top() {
         if (container_.empty())
             throw std::out_of_range("Stack is empty");
         return container_.front();
     }
 
     /**
      * @brief Returns the top element (const version).
      * @return Const reference to the top element.
      */
     const T& top() const {
         if (container_.empty())
             throw std::out_of_range("Stack is empty");
         return container_.front();
     }
 
     /// Checks if the stack is empty.
     bool empty() const { return container_.empty(); }
 
     /// Returns the number of elements in the stack.
     std::size_t size() const { return container_.size(); }
 
 private:
     Container container_; ///< Underlying container.
 };
 
 } // namespace dsa
 
 #endif // DSA_STACK_HPP
 