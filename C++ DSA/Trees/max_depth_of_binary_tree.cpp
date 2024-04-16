#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(){
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

Node* buildTree(Node* root){
    // cout<<"Enter the data: ";
    int data;
    cin>>data;
    root = new Node(data);
    if(data == -1) return NULL;

    // cout<<"Enter left child of "<<data<<": "<<endl;
    root->left = buildTree(root->left);
    // cout<<"Enter right child of "<<data<<": "<<endl;
    root->right = buildTree(root->right);

    return root;
}

int findDepth(Node* root, int& maxDepth, int depth){
    if(root == nullptr) return maxDepth;
    depth++;
    maxDepth = max(maxDepth, depth);
    findDepth(root->left, maxDepth, depth);
    findDepth(root->right, maxDepth, depth);

    return maxDepth;
}

int maxDepth(Node* root) {
    int maxDepth = 0;
    return findDepth(root, maxDepth, 0);
}

int main(){
    // 3 2 1 -1 2 -1 4 -1 -1 -1 -1
    Node* root = buildTree(root);
    cout<<maxDepth(root);
    return 0;
}