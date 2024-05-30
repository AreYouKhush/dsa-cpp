#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// A full binary tree is a binary tree where each node has either 0 or 2 children.

bool evaluateTree(TreeNode* root) {
    if(root->left == nullptr && root->right == nullptr) return root->val;

    if(root->val == 2)
        return evaluateTree(root->left) || evaluateTree(root->right);
    if(root->val == 3)
        return evaluateTree(root->left) && evaluateTree(root->right);
    return true;
}

TreeNode* createTree(vector<int>& tree) {
    TreeNode* root = new TreeNode(tree[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while(!q.empty() && i < tree.size()) {
        TreeNode* parent = q.front();
        q.pop();
        for(int dir = 0; dir < 2; dir++) {
            if(tree[i] != -1 && i < tree.size()) {
                TreeNode* newNode = new TreeNode(tree[i]);
                if(dir == 0)
                    parent->left = newNode;
                else
                    parent->right = newNode;
                q.push(newNode);
            }
            i++;
        }
    }
    return root;
}

void printTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if(temp == nullptr) {
            cout<<"\n";
            if(!q.empty()) {
                q.push(nullptr);
            }
        } else {
            cout<<temp->val<<" ";
            if(temp->left != nullptr) q.push(temp->left);
            if(temp->right != nullptr) q.push(temp->right);
        }
    }
}

int main() {
    vector<int> tree1 = {2,1,3,-1,-1,0,1};
    TreeNode* root = createTree(tree1);
    // printTree(root);
    cout<<(evaluateTree(root) ? "TRUE" : "FALSE");
    return 0;
}