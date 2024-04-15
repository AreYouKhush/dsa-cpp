Depth-first search (DFS) is another fundamental algorithm for traversing or searching tree and graph data structures. In the context of binary trees, DFS explores as far as possible along each branch before backtracking. There are mainly three types of DFS traversal for binary trees: pre-order, in-order, and post-order.

### Pre-order DFS:
In pre-order DFS, you visit the root node first, then recursively do a pre-order traversal of the left subtree, followed by a pre-order traversal of the right subtree.

### In-order DFS:
In in-order DFS, you recursively do an in-order traversal of the left subtree, visit the root node, and then recursively do an in-order traversal of the right subtree. In a binary search tree (BST), an in-order traversal returns the nodes in sorted order.

### Post-order DFS:
In post-order DFS, you recursively do a post-order traversal of the left subtree, followed by a post-order traversal of the right subtree, and finally visit the root node.

### Implementation in C++:

```
#include <iostream>

using namespace std;

// Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Pre-order DFS
void preOrderDFS(Node* root) {
    if (root == nullptr)
        return;
    
    cout << root->data << " ";  // Process the node
    preOrderDFS(root->left);    // Recursively traverse left subtree
    preOrderDFS(root->right);   // Recursively traverse right subtree
}

// In-order DFS
void inOrderDFS(Node* root) {
    if (root == nullptr)
        return;
    
    inOrderDFS(root->left);     // Recursively traverse left subtree
    cout << root->data << " ";  // Process the node
    inOrderDFS(root->right);    // Recursively traverse right subtree
}

// Post-order DFS
void postOrderDFS(Node* root) {
    if (root == nullptr)
        return;
    
    postOrderDFS(root->left);   // Recursively traverse left subtree
    postOrderDFS(root->right);  // Recursively traverse right subtree
    cout << root->data << " ";  // Process the node
}

int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Pre-order DFS: ";
    preOrderDFS(root);
    cout << endl;

    cout << "In-order DFS: ";
    inOrderDFS(root);
    cout << endl;

    cout << "Post-order DFS: ";
    postOrderDFS(root);
    cout << endl;

    return 0;
}
```