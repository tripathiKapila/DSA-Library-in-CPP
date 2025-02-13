#ifndef DSA_ARRAY_HPP
#define DSA_ARRAY_HPP

#include <cstddef>
#include <stdexcept>

namespace dsa {

template<typename T>
class DynamicArray {
public:
    DynamicArray();
    ~DynamicArray();

    void push_back(const T& value);
    void pop_back();
    T& operator[](std::size_t index);
    const T& operator[](std::size_t index) const;
    std::size_t size() const;
    std::size_t capacity() const;
private:
    void resize(std::size_t new_capacity);
    T* data_;
    std::size_t size_;
    std::size_t capacity_;
};

template<typename T>
DynamicArray<T>::DynamicArray() : data_(nullptr), size_(0), capacity_(0) {
    capacity_ = 4;
    data_ = new T[capacity_];
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data_;
}

template<typename T>
void DynamicArray<T>::push_back(const T& value) {
    if (size_ == capacity_) {
        resize(capacity_ * 2);
    }
    data_[size_++] = value;
}

template<typename T>
void DynamicArray<T>::pop_back() {
    if (size_ == 0)
        throw std::out_of_range("Array is empty");
    size_--;
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
        new_data[i] = data_[i];
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
}

} // namespace dsa

#endif // DSA_ARRAY_HPP
