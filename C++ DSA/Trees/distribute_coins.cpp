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

int dfs(TreeNode* root, int& moves) {
    if(root == nullptr) return 0;

    int left = dfs(root->left, moves);
    int right = dfs(root->right, moves);

    moves += abs(left) + abs(right);

    return root->val + left + right -1;
}

int distributeCoins(TreeNode* root) {
    int moves = 0;
    dfs(root, moves);
    return moves;
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
    vector<int> tree1 = {3,0,0,0,2,0,0,0,-1,-1,0,-1,-1,-1,6,0};
    vector<int> tree2 = {2,1,3,-1,-1,0,1,0,0};
    vector<int> tree3 = {0,0,0,0,0,0,0,0,0,0,0,0,13};
    TreeNode* root1 = createTree(tree1);
    TreeNode* root2 = createTree(tree2);
    TreeNode* root3 = createTree(tree3);
    // printTree(root1);
    // printTree(root2);
    // printTree(root3);
    cout<<distributeCoins(root1)<<endl;
    cout<<distributeCoins(root2)<<endl;
    cout<<distributeCoins(root3)<<endl;
    return 0;
}