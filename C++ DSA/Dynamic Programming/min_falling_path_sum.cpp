#include<bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>>& matrix, int m, int n, vector<vector<int>>& dp) {
    if(n < 0 || m < 0) return INT_MAX;
    if(m == 0) {
        if(n-1 >= 0 && n+1 < matrix[0].size())
            return min(matrix[m][n-1], min(matrix[m][n], matrix[m][n+1]));
        else if(n-1 < 0 && n+1 < matrix[0].size())
            return min(matrix[m][n], matrix[m][n+1]);
        else
            return matrix[m][n];
    }
    if(dp[m][n] != -1) return dp[m][n];

    int left = INT_MAX;
    int right = INT_MAX;
    if(n-1 >= 0)
        left = matrix[m][n-1] + helper(matrix, m-1, n-1, dp);
    if(n+1 < matrix[0].size())    
        right = matrix[m][n+1] + helper(matrix, m-1, n+1, dp);
    int up = matrix[m][n] + helper(matrix, m-1, n, dp);

    return dp[m][n] = min(left, min(up, right));
}

// Memoization
int minFallingPathSum_memo(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m-1, vector<int>(n, INT_MAX));
    int mini = INT_MAX;
    for(int i = n - 1; i >= 0; i--) {
        mini = min(mini, matrix[m-1][i] + helper(matrix, m-2, i, dp));
    }
    return mini;
}

//Tabulation
int minFallingPathSum_tab(vector<vector<int>>& matrix) {
    int m = matrix.size();
    vector<vector<int>> dp(m, vector<int>(m, INT_MAX));
    int mini = INT_MAX;

    for(int i = 0; i < m; i++) {

    }
}

int main() {
    // vector<vector<int>> matrix = {{-19,57},{-40,-5}};
    // vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    vector<vector<int>> matrix(100, vector<int>(100, 0));
    for(int i = 0; i < 100; i++) {
        matrix[26][i] = -1;
    }
    cout<<minFallingPathSum_memo(matrix);
    return 0;
}