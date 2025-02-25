/**
 * @file Queue.hpp
 * @brief Declares a container-customizable Queue implementation.
 */

 #ifndef DSA_QUEUE_HPP
 #define DSA_QUEUE_HPP
 
 #include "LinkedList.hpp"
 #include <stdexcept>
 #include <utility>
 
 namespace dsa {
 
 /**
  * @class Queue
  * @brief A queue implemented using an underlying container.
  *
  * By default, the Queue uses LinkedList as its container.
  *
  * @tparam T Type of elements.
  * @tparam Container Underlying container type.
  */
 template<typename T, typename Container = LinkedList<T>>
 class Queue {
 public:
     /// Default constructor.
     Queue() = default;
     /// Default destructor.
     ~Queue() = default;
 
     /// Enqueues an element.
     void enqueue(const T& value) { container_.push_back(value); }
     /// Enqueues an element (using move semantics).
     void enqueue(T&& value) { container_.push_back(std::move(value)); }
 
     /// Dequeues an element.
     void dequeue() {
         if (container_.empty())
             throw std::out_of_range("Queue is empty");
         container_.pop_front();
     }
 
     /**
      * @brief Returns the front element.
      * @return Reference to the front element.
      */
     T& front() {
         if (container_.empty())
             throw std::out_of_range("Queue is empty");
         return container_.front();
     }
 
     /**
      * @brief Returns the front element (const version).
      * @return Const reference to the front element.
      */
     const T& front() const {
         if (container_.empty())
             throw std::out_of_range("Queue is empty");
         return container_.front();
     }
 
     /// Checks if the queue is empty.
     bool empty() const { return container_.empty(); }
 
     /// Returns the number of elements in the queue.
     std::size_t size() const { return container_.size(); }
 
 private:
     Container container_; ///< Underlying container.
 };
 
 } // namespace dsa
 
 #endif // DSA_QUEUE_HPP
 