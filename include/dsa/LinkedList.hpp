/**
 * @file LinkedList.hpp
 * @brief Declares a singly linked list with iterator support.
 */

 #ifndef DSA_LINKEDLIST_HPP
 #define DSA_LINKEDLIST_HPP
 
 #include <cstddef>
 #include <stdexcept>
 #include <iterator>
 
 namespace dsa {
 
 /**
  * @struct Node
  * @brief Node structure for the linked list.
  *
  * @tparam T Type of data stored in the node.
  */
 template<typename T>
 struct Node {
     T data;      ///< Data stored in the node.
     Node* next;  ///< Pointer to the next node.
     /**
      * @brief Constructs a node with given value.
      * @param value The data for the node.
      */
     Node(const T& value) : data(value), next(nullptr) {}
 };
 
 /**
  * @class LinkedList
  * @brief A singly linked list with basic operations.
  *
  * Provides methods to add and remove elements, and supports iteration.
  *
  * @tparam T Type of elements stored in the list.
  */
 template<typename T>
 class LinkedList {
 public:
     /// Default constructor.
     LinkedList();
 
     /// Copy constructor.
     LinkedList(const LinkedList& other);
 
     /// Move constructor.
     LinkedList(LinkedList&& other) noexcept;
 
     /**
      * @brief Copy assignment operator.
      * @param other Another LinkedList.
      * @return Reference to this list.
      */
     LinkedList& operator=(LinkedList other);
 
     /// Destructor.
     ~LinkedList();
 
     /// Adds an element at the beginning.
     void push_front(const T& value);
 
     /// Adds an element at the end.
     void push_back(const T& value);
 
     /// Removes the first element.
     void pop_front();
 
     /// Checks if the list is empty.
     bool empty() const;
 
     /// Returns the number of elements.
     std::size_t size() const;
 
     /**
      * @brief Returns a reference to the first element.
      * @return Reference to the first element.
      * @throws std::out_of_range if the list is empty.
      */
     T& front();
 
     /**
      * @brief Returns a const reference to the first element.
      * @return Const reference to the first element.
      * @throws std::out_of_range if the list is empty.
      */
     const T& front() const;
 
     /**
      * @brief Iterator class for LinkedList.
      */
     class iterator {
     public:
         using iterator_category = std::forward_iterator_tag;
         using value_type        = T;
         using difference_type   = std::ptrdiff_t;
         using pointer           = T*;
         using reference         = T&;
         
         /**
          * @brief Constructs an iterator pointing to a node.
          * @param ptr Pointer to a Node.
          */
         iterator(Node<T>* ptr) : ptr_(ptr) {}
 
         /// Dereferences the iterator.
         reference operator*() const { return ptr_->data; }
 
         /// Access operator.
         pointer operator->() const { return &(ptr_->data); }
 
         /// Prefix increment.
         iterator& operator++() { ptr_ = ptr_->next; return *this; }
 
         /// Postfix increment.
         iterator operator++(int) { iterator temp = *this; ++(*this); return temp; }
 
         /// Equality comparison.
         bool operator==(const iterator& other) const { return ptr_ == other.ptr_; }
 
         /// Inequality comparison.
         bool operator!=(const iterator& other) const { return ptr_ != other.ptr_; }
     private:
         Node<T>* ptr_;
     };
 
     /// Returns iterator to beginning.
     iterator begin() { return iterator(head_); }
 
     /// Returns iterator to end.
     iterator end() { return iterator(nullptr); }
 
 private:
     Node<T>* head_;      ///< Pointer to the first node.
     Node<T>* tail_;      ///< Pointer to the last node.
     std::size_t size_;   ///< Number of nodes in the list.
 
     /// Copies nodes from another list.
     void copyFrom(const LinkedList& other);
 
     /// Clears all nodes.
     void clear();
 };
 
 template<typename T>
 LinkedList<T>::LinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}
 
 template<typename T>
 void LinkedList<T>::copyFrom(const LinkedList& other) {
     for (Node<T>* cur = other.head_; cur; cur = cur->next)
         push_back(cur->data);
 }
 
 template<typename T>
 LinkedList<T>::LinkedList(const LinkedList& other)
     : head_(nullptr), tail_(nullptr), size_(0) {
     copyFrom(other);
 }
 
 template<typename T>
 LinkedList<T>::LinkedList(LinkedList&& other) noexcept 
     : head_(other.head_), tail_(other.tail_), size_(other.size_) {
     other.head_ = other.tail_ = nullptr;
     other.size_ = 0;
 }
 
 template<typename T>
 LinkedList<T>& LinkedList<T>::operator=(LinkedList other) {
     std::swap(head_, other.head_);
     std::swap(tail_, other.tail_);
     std::swap(size_, other.size_);
     return *this;
 }
 
 template<typename T>
 LinkedList<T>::~LinkedList() {
     clear();
 }
 
 template<typename T>
 void LinkedList<T>::clear() {
     while(head_)
         pop_front();
 }
 
 template<typename T>
 void LinkedList<T>::push_front(const T& value) {
     Node<T>* new_node = new Node<T>(value);
     new_node->next = head_;
     head_ = new_node;
     if (!tail_)
         tail_ = new_node;
     ++size_;
 }
 
 template<typename T>
 void LinkedList<T>::push_back(const T& value) {
     Node<T>* new_node = new Node<T>(value);
     if (tail_)
         tail_->next = new_node;
     else
         head_ = new_node;
     tail_ = new_node;
     ++size_;
 }
 
 template<typename T>
 void LinkedList<T>::pop_front() {
     if (!head_)
         throw std::out_of_range("List is empty");
     Node<T>* temp = head_;
     head_ = head_->next;
     if (!head_)
         tail_ = nullptr;
     delete temp;
     --size_;
 }
 
 template<typename T>
 bool LinkedList<T>::empty() const {
     return size_ == 0;
 }
 
 template<typename T>
 std::size_t LinkedList<T>::size() const {
     return size_;
 }
 
 template<typename T>
 T& LinkedList<T>::front() {
     if (!head_)
         throw std::out_of_range("List is empty");
     return head_->data;
 }
 
 template<typename T>
 const T& LinkedList<T>::front() const {
     if (!head_)
         throw std::out_of_range("List is empty");
     return head_->data;
 }
 
 } // namespace dsa
 
 #endif // DSA_LINKEDLIST_HPP
 