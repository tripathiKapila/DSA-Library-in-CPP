#ifndef DSA_STACK_HPP
#define DSA_STACK_HPP

#include "LinkedList.hpp"

namespace dsa {

template<typename T>
class Stack {
public:
    Stack() = default;
    ~Stack() = default;

    void push(const T& value);
    void pop();
    T& top();
    const T& top() const;
    bool empty() const;
    std::size_t size() const;
private:
    LinkedList<T> list_;
};

template<typename T>
void Stack<T>::push(const T& value) {
    list_.push_front(value);
}

template<typename T>
void Stack<T>::pop() {
    list_.pop_front();
}

template<typename T>
T& Stack<T>::top() {
    return list_.front();
}

template<typename T>
const T& Stack<T>::top() const {
    return list_.front();
}

template<typename T>
bool Stack<T>::empty() const {
    return list_.empty();
}

template<typename T>
std::size_t Stack<T>::size() const {
    return list_.size();
}

} // namespace dsa

#endif // DSA_STACK_HPP
