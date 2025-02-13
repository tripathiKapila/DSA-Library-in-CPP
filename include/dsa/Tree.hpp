#ifndef DSA_TREE_HPP
#define DSA_TREE_HPP

#include <iostream>

namespace dsa {

template<typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(const T& value);
    bool search(const T& value) const;
    void inOrderTraversal() const;
private:
    TreeNode<T>* root_;
    void insert(TreeNode<T>*& node, const T& value);
    bool search(TreeNode<T>* node, const T& value) const;
    void inOrderTraversal(TreeNode<T>* node) const;
    void destroy(TreeNode<T>* node);
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree() : root_(nullptr) {}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    destroy(root_);
}

template<typename T>
void BinarySearchTree<T>::destroy(TreeNode<T>* node) {
    if (node) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

template<typename T>
void BinarySearchTree<T>::insert(const T& value) {
    insert(root_, value);
}

template<typename T>
void BinarySearchTree<T>::insert(TreeNode<T>*& node, const T& value) {
    if (!node) {
        node = new TreeNode<T>(value);
    } else if (value < node->data) {
        insert(node->left, value);
    } else if (value > node->data) {
        insert(node->right, value);
    }
}

template<typename T>
bool BinarySearchTree<T>::search(const T& value) const {
    return search(root_, value);
}

template<typename T>
bool BinarySearchTree<T>::search(TreeNode<T>* node, const T& value) const {
    if (!node)
        return false;
    if (node->data == value)
        return true;
    return value < node->data ? search(node->left, value) : search(node->right, value);
}

template<typename T>
void BinarySearchTree<T>::inOrderTraversal() const {
    inOrderTraversal(root_);
}

template<typename T>
void BinarySearchTree<T>::inOrderTraversal(TreeNode<T>* node) const {
    if (node) {
        inOrderTraversal(node->left);
        std::cout << node->data << " ";
        inOrderTraversal(node->right);
    }
}

} // namespace dsa

#endif // DSA_TREE_HPP
