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

void preorder(Node* root){
    if(root == nullptr) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void dfs(Node* root, int val, int depth, int currDepth){
    if(root == nullptr) return;

    currDepth++;
    if(currDepth == depth){
        Node* l = new Node(val);
        l->left = root->left;
        root->left = l;
        Node* r = new Node(val);
        r->right = root->right;
        root->right = r;
    }
    dfs(root->left, val, depth, currDepth);
    dfs(root->right, val, depth, currDepth);
}

Node* addOneRow(Node* root, int val, int depth) {
    if(depth == 1){
        Node* temp = new Node(val);
        temp->left = root;
        root = temp;
        return root;
    }

    dfs(root, val, depth, 1);

    return root;
}

int main(){
    // 4 2 3 -1 -1 1 -1 -1 6 5 -1 -1 -1
    Node* root = buildTree(root);
    // Node* temp = root;
    // preorder(temp);
    addOneRow(root, 1, 2);
    preorder(root);
}