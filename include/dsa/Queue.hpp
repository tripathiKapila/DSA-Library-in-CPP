#ifndef DSA_QUEUE_HPP
#define DSA_QUEUE_HPP

#include "LinkedList.hpp"

namespace dsa {

template<typename T>
class Queue {
public:
    Queue() = default;
    ~Queue() = default;

    void enqueue(const T& value);
    void dequeue();
    T& front();
    const T& front() const;
    bool empty() const;
    std::size_t size() const;
private:
    LinkedList<T> list_;
};

template<typename T>
void Queue<T>::enqueue(const T& value) {
    list_.push_back(value);
}

template<typename T>
void Queue<T>::dequeue() {
    list_.pop_front();
}

template<typename T>
T& Queue<T>::front() {
    return list_.front();
}

template<typename T>
const T& Queue<T>::front() const {
    return list_.front();
}

template<typename T>
bool Queue<T>::empty() const {
    return list_.empty();
}

template<typename T>
std::size_t Queue<T>::size() const {
    return list_.size();
}

} // namespace dsa

#endif // DSA_QUEUE_HPP
