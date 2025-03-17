/**
 * @file Tree.hpp
 * @brief Declares a binary search tree (BST) with in-order traversal.
 */

 #ifndef DSA_TREE_HPP
 #define DSA_TREE_HPP
 
 #include <iostream>
 #include <stack>
 #include <stdexcept>
 
 namespace dsa {
 
 /**
  * @struct TreeNode
  * @brief Node structure for the binary search tree.
  *
  * @tparam T Type of data stored.
  */
 template<typename T>
 struct TreeNode {
     T data;              ///< Data contained in the node.
     TreeNode* left;      ///< Pointer to left child.
     TreeNode* right;     ///< Pointer to right child.
     /**
      * @brief Constructs a tree node.
      * @param value Data value for the node.
      */
     TreeNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
 };
 
 /**
  * @class BinarySearchTree
  * @brief A basic binary search tree.
  *
  * Provides methods to insert, search, and traverse the BST in order.
  *
  * @tparam T Type of elements in the BST.
  */
 template<typename T>
 class BinarySearchTree {
 public:
     /// Default constructor.
     BinarySearchTree();
     /// Copy constructor.
     BinarySearchTree(const BinarySearchTree& other);
     /// Move constructor.
     BinarySearchTree(BinarySearchTree&& other) noexcept;
     /**
      * @brief Copy assignment operator.
      * @param other Another BST.
      * @return Reference to this BST.
      */
     BinarySearchTree& operator=(BinarySearchTree other);
     /// Destructor.
     ~BinarySearchTree();
 
     /// Inserts a value into the BST.
     void insert(const T& value);

     /**
      * @brief Removes a value from the BST.
      * @param value Value to remove.
      * @return True if removed, false if not found.
      */
     bool remove(const T& value);
 
     /**
      * @brief Searches for a value in the BST.
      * @param value Value to search for.
      * @return True if found, false otherwise.
      */
     bool search(const T& value) const;
 
     /// Performs an in-order traversal of the BST.
     void inOrderTraversal() const;
 
     /**
      * @brief In-order iterator class.
      */
     class iterator {
     public:
         /**
          * @brief Constructs an iterator starting at a given node.
          * @param root Root node to start the traversal.
          */
         iterator(TreeNode<T>* root) { pushLeft(root); }
 
         /// Dereferences the iterator.
         T& operator*() { return node_stack.top()->data; }
 
         /// Prefix increment operator.
         iterator& operator++() {
             TreeNode<T>* node = node_stack.top();
             node_stack.pop();
             pushLeft(node->right);
             return *this;
         }
 
         /// Inequality comparison operator.
         bool operator!=(const iterator& other) const {
             return node_stack != other.node_stack;
         }
     private:
         std::stack<TreeNode<T>*> node_stack; ///< Stack for traversal.
         void pushLeft(TreeNode<T>* node) {
             while (node) {
                 node_stack.push(node);
                 node = node->left;
             }
         }
         friend class BinarySearchTree<T>;
     };
 
     /// Returns iterator to beginning of in-order traversal.
     iterator begin() { return iterator(root_); }
     /// Returns iterator representing end of traversal.
     iterator end() { return iterator(nullptr); }
 
 private:
     TreeNode<T>* root_; ///< Root node of the BST.
 
     /// Recursively inserts a value starting from a node.
     void insert(TreeNode<T>*& node, const T& value);
     /// Recursively removes a value.
     bool remove(TreeNode<T>*& node, const T& value);
     /// Finds the minimum value node in a subtree.
     TreeNode<T>* findMin(TreeNode<T>* node);
     /// Recursively searches for a value.
     bool search(TreeNode<T>* node, const T& value) const;
     /// Recursively performs in-order traversal.
     void inOrderTraversal(TreeNode<T>* node) const;
     /// Recursively destroys the BST.
     void destroy(TreeNode<T>* node);
     /// Recursively clones a BST.
     TreeNode<T>* clone(TreeNode<T>* node);
 };

 // Define Tree as an alias for BinarySearchTree for backward compatibility
 template<typename T>
 using Tree = BinarySearchTree<T>;
 
 template<typename T>
 BinarySearchTree<T>::BinarySearchTree() : root_(nullptr) {}
 
 template<typename T>
 TreeNode<T>* BinarySearchTree<T>::clone(TreeNode<T>* node) {
     if (!node) return nullptr;
     TreeNode<T>* new_node = new TreeNode<T>(node->data);
     new_node->left = clone(node->left);
     new_node->right = clone(node->right);
     return new_node;
 }
 
 template<typename T>
 BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& other)
     : root_(clone(other.root_)) {}
 
 template<typename T>
 BinarySearchTree<T>::BinarySearchTree(BinarySearchTree&& other) noexcept 
     : root_(other.root_) {
     other.root_ = nullptr;
 }
 
 template<typename T>
 BinarySearchTree<T>& BinarySearchTree<T>::operator=(BinarySearchTree other) {
     std::swap(root_, other.root_);
     return *this;
 }
 
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
     if (!node)
         node = new TreeNode<T>(value);
     else if (value < node->data)
         insert(node->left, value);
     else if (value > node->data)
         insert(node->right, value);
 }

 template<typename T>
 bool BinarySearchTree<T>::remove(const T& value) {
     return remove(root_, value);
 }

 template<typename T>
 bool BinarySearchTree<T>::remove(TreeNode<T>*& node, const T& value) {
     if (!node) return false;
     
     if (value < node->data) {
         return remove(node->left, value);
     } else if (value > node->data) {
         return remove(node->right, value);
     } else {
         // Found the node to remove
         
         // Case 1: No children
         if (!node->left && !node->right) {
             delete node;
             node = nullptr;
         }
         // Case 2: One child
         else if (!node->left) {
             TreeNode<T>* temp = node;
             node = node->right;
             delete temp;
         }
         else if (!node->right) {
             TreeNode<T>* temp = node;
             node = node->left;
             delete temp;
         }
         // Case 3: Two children
         else {
             TreeNode<T>* temp = findMin(node->right);
             node->data = temp->data;
             remove(node->right, temp->data);
         }
         return true;
     }
 }

 template<typename T>
 TreeNode<T>* BinarySearchTree<T>::findMin(TreeNode<T>* node) {
     if (!node) return nullptr;
     while (node->left) {
         node = node->left;
     }
     return node;
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
 