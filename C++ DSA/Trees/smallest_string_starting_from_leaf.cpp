
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

void dfs(Node* root, string& smallest, string current, int sum, int& smallestSum){
    char c = 'a';
    if(root == nullptr) return;
    sum += root->data;
    current += (c + root->data);

    if(root->left == nullptr && root->right == nullptr){
        // if(smallestSum > sum){
        //     smallestSum = sum;
        //     smallest = current;
        // }
        if(smallest == "") smallest = current;
        else smallest = min(smallest, current);
    }

    dfs(root->left, smallest, current, sum, smallestSum);
    dfs(root->right, smallest, current, sum, smallestSum);
}

string smallestFromLeaf(Node* root) {
    string ans = "";
    int smallestSum = INT_MAX;
    dfs(root, ans, "", 0, smallestSum);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    // 3 2 1 -1 2 -1 4 -1 -1 -1 -1
    // 0 1 3 -1 -1 4 -1 -1 2 3 -1 -1 4 -1 -1
    Node* root = buildTree(root);
    cout<<smallestFromLeaf(root);
    return 0;
}