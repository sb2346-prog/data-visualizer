#include "BST.h"
#include <iostream>

BST::BST() : root(nullptr) {}

BSTNode* BST::insert(BSTNode* node, int val) {
    if (!node) return new BSTNode(val);
    if (val < node->data) node->left = insert(node->left, val);
    else node->right = insert(node->right, val);
    return node;
}
void BST::insert(int val) { root = insert(root, val); }
BSTNode* BST::findMin(BSTNode* node) {
    while (node && node->left) node = node->left;
    return node;
}
BSTNode* BST::remove(BSTNode* node, int val) {
    if (!node) return nullptr;
    if (val < node->data) node->left = remove(node->left, val);
    else if (val > node->data) node->right = remove(node->right, val);
    else {
        if (!node->left) { BSTNode* temp = node->right; delete node; return temp; }
        else if (!node->right) { BSTNode* temp = node->left; delete node; return temp; }
        BSTNode* temp = findMin(node->right);
        node->data = temp->data;
        node->right = remove(node->right, temp->data);
    }
    return node;
}

void BST::remove(int val) { root = remove(root, val); }

void BST::inOrderTraversal(BSTNode* node) {
    if (!node) return;
    inOrderTraversal(node->left);
    std::cout << node->data << " ";
    inOrderTraversal(node->right);
}
void BST::preOrderTraversal(BSTNode* node) {
    if (!node) return;
    std::cout << node->data << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}
void BST::postOrderTraversal(BSTNode* node) {
    if (!node) return;
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    std::cout << node->data << " ";
}
void BST::inOrder() { inOrderTraversal(root); std::cout << std::endl; }
void BST::preOrder() { preOrderTraversal(root); std::cout << std::endl; }
void BST::postOrder() { postOrderTraversal(root); std::cout << std::endl; }
void BST::exportToDLL(DoublyLinkedList<int>& list) { exportToDLLHelper(root, list); }
void BST::exportToDLLHelper(BSTNode* node, DoublyLinkedList<int>& list) {
    if (!node) return;
    exportToDLLHelper(node->left, list);
    list.insertBack(node->data);
    exportToDLLHelper(node->right, list);
}

