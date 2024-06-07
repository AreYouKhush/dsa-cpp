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

class Solution {
public: 
    void helper(TreeNode* root,vector<vector<int>>& ans,vector<int>& temp,int targetSum){
        if(root==NULL)return;
        if(!root->left && !root->right){
            if(targetSum-root->val==0){
                temp.push_back(root->val);
                ans.push_back(temp);
                temp.pop_back();
                return;
            }
        }
        temp.push_back(root->val);
        helper(root->left,ans,temp,targetSum-root->val);
        helper(root->right,ans,temp,targetSum-root->val);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        vector<vector<int>> ans;
        vector<int> temp;
        helper(root,ans,temp,targetSum);
        return ans;
    }
};

int main() {
    return 0;
}