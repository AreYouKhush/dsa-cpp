#include<bits/stdc++.h>
using namespace std;

/*
    Types of Binary Tree:-
    1. Full Binary Tree
    2. Complete BT
    3. Perfect BT
    4. Balanced BT
    5. Degenerate BT
*/

/*
    Types of Traversal Techinques:-
    1. BFS -> Levels
    2. DFS
    Types of Tree Traversals (DFS) :-
    1. Inorder -> Left + Root + Right
    2. Preorder -> Root + Left + Right
    3. Postorder -> Left + Right + Root
*/

template<typename T>
class Node{
    public:
    T data;
    Node<T>* left;
    Node<T>* right;
    Node(){
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }
    Node(T data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    Node(T data, Node* left, Node* right){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

//Interative
Node<int>* createTree(vector<int>& nums){ 
    if (nums.empty()) {
        return NULL;
    }
    Node<int>* root = new Node<int>(nums[0]);
    queue<Node<int>*> q;
    q.push(root);
    int i = 1;
    while (i < nums.size()) {
        Node<int>* curr = q.front();
        q.pop();
        if (i < nums.size()) {
            curr->left = new Node<int>(nums[i++]);
            q.push(curr->left);
        }
        if (i < nums.size()) {
            curr->right = new Node<int>(nums[i++]);
            q.push(curr->right);
        }
    }
    return root;
}

void levelOrderTraversal(Node<int>* root){
    queue<Node<int>*> q;
    q.push(root);
    q.push(NULL); //Seperator

    while(!q.empty()){
        Node<int>* temp = q.front();
        q.pop();
        if(temp == NULL){
            //Level Complete
            cout<<endl;
            if(!q.empty()){
                //Queue still has some child nodes
                q.push(NULL);
            }
        }else{
        cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void printTree(Node<int>* root) {
    if (!root) {
        return;
    }
      printTree(root->left);
    cout << root->data << " ";
   
    printTree(root->right);
} 

int main(){
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    Node<int>* root = createTree(vec);
    // printTree(root);
    levelOrderTraversal(root);
    return 0;
}