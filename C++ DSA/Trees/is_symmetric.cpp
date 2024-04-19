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

bool isSymmetric(Node* l, Node* r){
    if(l == nullptr && r == nullptr) return true;
    else if(l == nullptr || r == nullptr) return false;
    
    bool i = isSymmetric(l->left, r->right);
    bool j = isSymmetric(l->right, r->left);

    return i && j && l->data == r->data;
}

int main(){
    // vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    // Node<int>* root = createTree(vec);
    // 1 2 3 -1 -1 4 -1 -1 2 4 -1 -1 3 -1 -1

    Node* root = buildTree(root);

    // printTree(root);
    int ans = true;
    if(root->left != nullptr && root->right != nullptr) ans = isSymmetric(root->left, root->right);
    cout<<ans;
    return 0;
}