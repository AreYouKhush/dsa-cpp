#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int left = 0, right = matrix[0].size() - 1;
    int top = left, bottom = matrix.size() - 1;
    while(left <= right && top <= bottom){
        if(top != bottom && left != right){
            for(int j = left; j <= right; j++){
                ans.push_back(matrix[top][j]);
            }
            if(bottom - top - 1 > 0){
                for(int k = top + 1; k < bottom; k++){
                    ans.push_back(matrix[k][right]);
                }
            }
            for(int j = right; j >= left; j--){
                ans.push_back(matrix[bottom][j]);
            }
            if(bottom - top - 1 > 0){
                for(int k = bottom - 1; k > top; k--){
                    ans.push_back(matrix[k][left]);
                }
            }
        }else if (top == bottom && left != right){
            for(int j = left; j <= right; j++){
                ans.push_back(matrix[top][j]);
            }
        }else if(top != bottom && left == right){
            for(int k = top; k <= bottom; k++){
                ans.push_back(matrix[k][left]);
            }
        }else{
            for(int j = left; j <= right; j++){
                ans.push_back(matrix[top][j]);
            }
        }
        left++;
        right--;
        top++;
        bottom--;
    }
    return ans;
}     

int main(){
    vector<vector<int>> inp = {{2,-3,6,2,5},{-2,3,-3,-3,-4},{4,-6,9,5,9},{-2,3,3,-4,1}};
    // vector<vector<int>> inp = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> ans = spiralOrder(inp);
    for(auto it : ans){
        cout<<it<<" ";
    }
}