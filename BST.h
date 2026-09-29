#ifndef BST_h
#define BST_h

#include "DoublyLinkedList.h"

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    BSTNode* root;
    BSTNode* insert(BSTNode* node, int val);
    BSTNode* remove(BSTNode* node, int val);
    BSTNode* findMin(BSTNode* node);
    void inOrderTraversal(BSTNode* node);
    void preOrderTraversal(BSTNode* node);
    void postOrderTraversal(BSTNode* node);
    void exportToDLLHelper(BSTNode* node, DoublyLinkedList<int>& list);

public:
    BST();
    void insert(int val);
    void remove(int val);
    void inOrder();
    void preOrder();
    void postOrder();
    void exportToDLL(DoublyLinkedList<int>& list);
};

#endif


