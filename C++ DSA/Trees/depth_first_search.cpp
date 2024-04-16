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

void preOrderDFS(Node* root){
    if(root == nullptr) return;

    cout<<root->data<<" ";
    preOrderDFS(root->left);
    preOrderDFS(root->right);
}

void iterPreOrder(Node* root){
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* temp = st.top();
        st.pop();
        cout<<temp->data<<" ";
        if(temp->right != nullptr) st.push(temp->right);
        if(temp->left != nullptr) st.push(temp->left);
    }
}

void inOrderDFS(Node* root){
    if(root == nullptr) return;

    inOrderDFS(root->left);
    cout<<root->data<<" ";
    inOrderDFS(root->right);
}

void iterInOrder(Node* root){
    stack<Node*> st;
    Node* node = root;
    while(true){
        if(node == nullptr){
            if(st.empty() == true) break;
            node = st.top();
            st.pop();
            cout<<node->data<<" ";
            node = node->right;
        }else{
            st.push(node);
            node = node->left;
        }
        
    }
}

void postOrderDFS(Node* root){
    if(root == nullptr) return;

    postOrderDFS(root->left);
    postOrderDFS(root->right);
    cout<<root->data<<" ";
}

void iterPostOrder2Stack(Node* root){
    stack<Node*> st1;
    stack<Node*> st2;
    if(root == nullptr) return;
    st1.push(root);
    while(!st1.empty()){
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left != nullptr) st1.push(root->left);
        if(root->right != nullptr) st1.push(root->right);
    }
    while(!st2.empty()){
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
}

void iterPostOrder1Stack(Node* root){
    stack<Node*> st;
    vector<int> postorder;
    Node* curr = root;
    while(curr != nullptr || !st.empty()){
        if(curr != nullptr){
            st.push(curr);
            curr = curr->left;
        }else{
            Node* temp = st.top()->right;
            if(temp == nullptr){
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }else{
                curr = temp;
            }
        }
    }
    for(int i: postorder){
        cout<<i<<" ";
    }
}

int main(){
    // 4 9 5 -1 -1 1 -1 -1 0 -1 -1
    // 5 7 5 -1 -1 1 -1 -1 3 3 -1 -1 -1
    // 7 3 8 -1 -1 7 -1 -1 9 5 -1 -1 -1
    // 7 3 8 -1 -1 7 -1 -1 9 5 -1 -1 1 -1 -1
    Node* root = buildTree(root);
    // iterPreOrder(root);
    // iterInOrder(root);
    // iterPostOrder2Stack(root);
    iterPostOrder1Stack(root);

    // preOrderDFS(root);
    // cout<<endl;
    // inOrderDFS(root);
    // cout<<endl;
    // postOrderDFS(root);
    return 0;
}