#include<bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& dp) {
    if(row < 0 || col < 0) return INT_MAX;
    if(row == 0) return triangle[0][0];
    if(dp[row][col] != INT_MAX) return dp[row][col];

    int up = INT_MAX;
    if(col >= triangle[row-1].size())
        up = triangle[row][col] + helper(triangle, row-1, triangle[row-1].size()-1, dp);
    else
        up = triangle[row][col] + helper(triangle, row-1, col, dp);
    int right = INT_MAX;
    if(col-1 >= 0) right = triangle[row][col] + helper(triangle, row-1, col-1, dp);

    return dp[row][col] = min(up, right);
}

// Memoization
int minimumTotal_memo(vector<vector<int>>& triangle) {
    int m = triangle.size();
    vector<vector<int>> dp(m, vector<int>(m, INT_MAX));
    int mini = INT_MAX;
    for(int i = m-1; i >= 0; i--) {
        mini = min(mini, helper(triangle, m-1, i, dp));
    }
    return mini;
}

//Tabulation
int minimumTotal_tab(vector<vector<int>>& triangle) {
    int m = triangle.size();
    vector<vector<int>> dp(m, vector<int>(m, INT_MAX));
    int mini = INT_MAX;

    dp[0][0] = triangle[0][0];

    for(int i = 1; i < m; i++) {
        for(int j = 0; j < triangle[i].size(); j++) {
            int up = INT_MAX;
            if(j < triangle[i-1].size()) up = dp[i-1][j] + triangle[i][j];

            int left = INT_MAX;
            if(j-1 >= 0) left = dp[i-1][j-1] + triangle[i][j];

            dp[i][j] = min(up, left);
        }
    }

    for(int i = 0; i < m; i++) {
        mini = min(mini, dp[m-1][i]);
    }

    return mini;
}

// space optimization
int minimumTotal(vector<vector<int>>& triangle) {
    int m = triangle.size();
    vector<int> dp(m, INT_MAX);
    int mini = INT_MAX;

    dp[0] = triangle[0][0];

    for(int i = 1; i < m; i++) {
        vector<int> cur(m, INT_MAX);
        for(int j = 0; j < triangle[i].size(); j++) {
            int up = INT_MAX;
            if(j < triangle[i-1].size()) up = dp[j] + triangle[i][j];

            int left = INT_MAX;
            if(j-1 >= 0) left = dp[j-1] + triangle[i][j];

            cur[j] = min(up, left);
        }
        dp = cur;
    }

    for(int i = 0; i < m; i++) {
        mini = min(mini, dp[i]);
    }

    return mini;
}

int main() {
    vector<vector<int>> triangle1 = {{2},{3,4},{6,5,7},{4,1,8,3}};
    vector<vector<int>> triangle2 = {{20}, {20,20},{20,2,20}, {20,20,20,20}, {20,20,2,20,20}};
    vector<vector<int>> triangle3;

    // for(int i = 0; i < 100; i++){
    //     vector<int> temp;
    //     for(int j = 0; j < i+1; j++){
    //         temp.push_back(rand()%10000);
    //     }
    //     triangle3.push_back(temp);
    // }

    cout<<minimumTotal(triangle1)<<endl;
    cout<<minimumTotal(triangle2)<<endl;
    // cout<<minimumTotal(triangle3)<<endl;
    return 0;
}