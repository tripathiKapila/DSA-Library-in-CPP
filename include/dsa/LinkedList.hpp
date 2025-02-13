#ifndef DSA_LINKEDLIST_HPP
#define DSA_LINKEDLIST_HPP

#include <cstddef>
#include <stdexcept>

namespace dsa {

template<typename T>
struct Node {
    T data;
    Node* next;
    Node(const T& value) : data(value), next(nullptr) {}
};

template<typename T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    bool empty() const;
    std::size_t size() const;
    T& front();
    const T& front() const;
private:
    Node<T>* head_;
    Node<T>* tail_;
    std::size_t size_;
};

template<typename T>
LinkedList<T>::LinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}

template<typename T>
LinkedList<T>::~LinkedList() {
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
    if (tail_) {
        tail_->next = new_node;
    } else {
        head_ = new_node;
    }
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
