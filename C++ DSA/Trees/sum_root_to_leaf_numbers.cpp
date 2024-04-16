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

void preOrderDFS(Node* root, int& sum, int n){
    n = (n*10) + root->data;
    if(root->left == nullptr && root->right == nullptr){
        sum += n;
        return;
    }
    if(root->left == nullptr) return;
    preOrderDFS(root->left, sum, n);
    if(root->right == nullptr) return;
    preOrderDFS(root->right, sum, n);
}

int main(){
    // 4 9 5 -1 -1 1 -1 -1 0 -1 -1
    // 1 0 0 -1 -1 -1 0 -1 -1
    // 1 0 0 -1 -1 -1 0 -1 0 -1 -1
    Node* root = buildTree(root);
    int sum = 0;
    int n = 0;
    preOrderDFS(root, sum, n);
    cout<<sum;
    return 0;
}