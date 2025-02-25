/**
 * @file Array.hpp
 * @brief Defines the DynamicArray class template.
 *
 * This file declares a resizable array implementation that supports robust
 * copy/move semantics and dynamic resizing.
 */

 #ifndef DSA_ARRAY_HPP
 #define DSA_ARRAY_HPP
 
 #include <cstddef>
 #include <stdexcept>
 #include <algorithm>
 #include <utility>
 
 namespace dsa {
 
 /**
  * @class DynamicArray
  * @brief A dynamic, resizable array.
  *
  * The DynamicArray class provides an array that automatically resizes as new
  * elements are added. It supports both copy and move semantics.
  *
  * @tparam T Type of elements stored in the array.
  */
 template<typename T>
 class DynamicArray {
 public:
     /// Default constructor.
     DynamicArray();
 
     /// Copy constructor.
     DynamicArray(const DynamicArray& other);
 
     /// Move constructor.
     DynamicArray(DynamicArray&& other) noexcept;
 
     /**
      * @brief Copy assignment operator.
      *
      * Uses the copy-and-swap idiom to ensure strong exception safety.
      *
      * @param other Another DynamicArray.
      * @return Reference to this DynamicArray.
      */
     DynamicArray& operator=(DynamicArray other);
 
     /// Destructor.
     ~DynamicArray();
 
     /**
      * @brief Adds an element to the end of the array.
      *
      * @param value Element to be added.
      */
     void push_back(const T& value);
 
     /**
      * @brief Adds an element (using move semantics) to the end of the array.
      *
      * @param value Element to be added.
      */
     void push_back(T&& value);
 
     /// Removes the last element.
     void pop_back();
 
     /**
      * @brief Accesses an element by index.
      *
      * @param index Index of the element.
      * @return Reference to the element.
      * @throws std::out_of_range if index is invalid.
      */
     T& operator[](std::size_t index);
 
     /**
      * @brief Const version of operator[].
      *
      * @param index Index of the element.
      * @return Const reference to the element.
      * @throws std::out_of_range if index is invalid.
      */
     const T& operator[](std::size_t index) const;
 
     /// @brief Returns the number of elements.
     std::size_t size() const;
 
     /// @brief Returns the current capacity.
     std::size_t capacity() const;
 
 private:
     /// Resizes the array to the new capacity.
     void resize(std::size_t new_capacity);
 
     /// Swaps the contents of two arrays.
     void swap(DynamicArray& other) noexcept;
 
     T* data_;             ///< Pointer to the array.
     std::size_t size_;    ///< Current number of elements.
     std::size_t capacity_;///< Current capacity of the array.
 };
 
 template<typename T>
 DynamicArray<T>::DynamicArray() : data_(new T[4]), size_(0), capacity_(4) {}
 
 template<typename T>
 DynamicArray<T>::DynamicArray(const DynamicArray& other)
     : data_(new T[other.capacity_]), size_(other.size_), capacity_(other.capacity_) {
     for (std::size_t i = 0; i < size_; ++i)
         data_[i] = other.data_[i];
 }
 
 template<typename T>
 DynamicArray<T>::DynamicArray(DynamicArray&& other) noexcept 
     : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
     other.data_ = nullptr;
     other.size_ = other.capacity_ = 0;
 }
 
 template<typename T>
 DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray other) {
     swap(other);
     return *this;
 }
 
 template<typename T>
 DynamicArray<T>::~DynamicArray() {
     delete[] data_;
 }
 
 template<typename T>
 void DynamicArray<T>::swap(DynamicArray& other) noexcept {
     std::swap(data_, other.data_);
     std::swap(size_, other.size_);
     std::swap(capacity_, other.capacity_);
 }
 
 template<typename T>
 void DynamicArray<T>::push_back(const T& value) {
     if (size_ == capacity_)
         resize(capacity_ * 2);
     data_[size_++] = value;
 }
 
 template<typename T>
 void DynamicArray<T>::push_back(T&& value) {
     if (size_ == capacity_)
         resize(capacity_ * 2);
     data_[size_++] = std::move(value);
 }
 
 template<typename T>
 void DynamicArray<T>::pop_back() {
     if (size_ == 0)
         throw std::out_of_range("Array is empty");
     --size_;
 }
 
 template<typename T>
 T& DynamicArray<T>::operator[](std::size_t index) {
     if (index >= size_)
         throw std::out_of_range("Index out of range");
     return data_[index];
 }
 
 template<typename T>
 const T& DynamicArray<T>::operator[](std::size_t index) const {
     if (index >= size_)
         throw std::out_of_range("Index out of range");
     return data_[index];
 }
 
 template<typename T>
 std::size_t DynamicArray<T>::size() const {
     return size_;
 }
 
 template<typename T>
 std::size_t DynamicArray<T>::capacity() const {
     return capacity_;
 }
 
 template<typename T>
 void DynamicArray<T>::resize(std::size_t new_capacity) {
     T* new_data = new T[new_capacity];
     for (std::size_t i = 0; i < size_; ++i)
         new_data[i] = std::move_if_noexcept(data_[i]);
     delete[] data_;
     data_ = new_data;
     capacity_ = new_capacity;
 }
 
 } // namespace dsa
 
 #endif // DSA_ARRAY_HPP
 