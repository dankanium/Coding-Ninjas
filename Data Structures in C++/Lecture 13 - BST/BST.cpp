#include "BinaryTreeNode.h"
class BST {
    BinaryTreeNode<int> *root;
    bool hasData(BinaryTreeNode<int> *node, int data) {
        if (node == NULL)
            return false;
        if (node->data == data)
            return true;
        if (data < node->data)
            return hasData(node->left, data);
        else
            return hasData(node->right, data);
    }
    public:
    BST() {
        root = NULL;
    }
    ~BST() {
        delete root;
    }
    void deleteData(int data) {

    }
    void insert(int data) {

    }
    bool hasData(int data) {
        return hasData(root, data);
    }
};