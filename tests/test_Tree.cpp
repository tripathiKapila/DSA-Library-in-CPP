/**
 * @file test_Tree.cpp
 * @brief Tests the BinarySearchTree class.
 */

 #include <cassert>
 #include "dsa/Tree.hpp"
 
 int main() {
     dsa::BinarySearchTree<int> bst;
     bst.insert(15);
     bst.insert(10);
     bst.insert(20);
     assert(bst.search(10));
     assert(!bst.search(5));
     return 0;
 }
 