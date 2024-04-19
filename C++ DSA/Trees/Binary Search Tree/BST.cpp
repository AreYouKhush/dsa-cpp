#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;
    BST() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

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

    void preorderTraversal(Node* root){
        if(root == nullptr) return;

        cout<<root->data<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }

    bool search(int key) {
        Node* temp = root;
        while(true){
            if(temp == nullptr){
                break;
            }else if(key == temp->data){
                return true;
            }else if(key > temp->data){
                temp = temp->right;
            }else if(key < temp->data){
                temp = temp->left;
            }
        }
        return false;
    }

    Node* searchRecursive(Node* root, int key) {
        if (root == nullptr || root->data == key) {
            return root;
        }

        if (key < root->data) {
            return searchRecursive(root->left, key);
        } else {
            return searchRecursive(root->right, key);
        }
    }

    void deleteNode(int key){
        Node* temp = root;
        while(true){
            if(temp == nullptr) break;
            
        }
    }

    // Other functions like search, delete, traversal methods can be implemented here
};

int main() {
    BST bst;
    vector<int> treeNodes = {1, 50, 30, 20, 40, 70, 60, 80};
    
    for(int i: treeNodes){
        bst.insert(i);
    }

    bst.preorderTraversal(bst.root);
    cout<<endl;
    cout<<bst.search(71);
    cout<<endl;
    cout<<bst.search(70);
    cout<<endl;

    cout<<(bst.searchRecursive(bst.root, 510) != nullptr);

    // Perform operations on the BST
    // Example: bst.search(60);

    return 0;
}