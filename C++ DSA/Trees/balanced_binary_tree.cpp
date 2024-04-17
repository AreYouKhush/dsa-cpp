
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

    int height(Node* root){
        if(root == nullptr) return 0;

        int lh = height(root->left);
        if(lh == -1) return -1;
        int rh = height(root->right);
        if(rh == -1) return -1;


        if(abs(lh - rh) > 1) return -1;

        return max(lh, rh) + 1;
    }

    bool isBalanced(Node* root) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        return height(root) != -1;
    }

int main(){
    // 3 2 1 -1 2 -1 4 -1 -1 -1 -1
    // 0 1 3 -1 -1 4 -1 -1 2 3 -1 -1 4 -1 -1
    Node* root = buildTree(root);
    cout<<isBalanced(root);
    return 0;
}