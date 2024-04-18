# Binary Search Tree (BST)

A Binary Search Tree (BST) is a hierarchical data structure used for organizing elements. In a BST, each node has at most two children: a left child and a right child. The key property of a BST is that for every node, all elements in its left subtree are less than or equal to the node's value, and all elements in its right subtree are greater than the node's value.

## Conditions to Make a BST:
1. Each node has at most two children.
2. For any node, all elements in its left subtree are less than or equal to the node's value.
3. For any node, all elements in its right subtree are greater than the node's value.
4. No duplicate nodes are allowed.

## Implementation in C++:

```
#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insertRecursive(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insertRecursive(root->left, value);
        } else if (value > root->data) {
            root->right = insertRecursive(root->right, value);
        }

        return root;
    }

public:
    BST() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Other functions like search, delete, traversal methods can be implemented here
};

int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Perform operations on the BST
    // Example: bst.search(60);

    return 0;
}
```