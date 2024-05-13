#include<bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>>& matrix, int m, int n, vector<vector<int>>& dp) {
    if(n < 0 || m < 0 || n >= matrix[0].size()) return INT_MAX;
    if(m == 0) {
        int mini = matrix[m][n];
        if(n-1 >= 0)
            mini = min(mini, matrix[m][n-1]);
        if(n+1 < matrix[0].size())
            mini = min(mini, matrix[m][n+1]);
        return mini;
    }
    if(dp[m][n] != INT_MAX) return dp[m][n];

    int left = INT_MAX;
    int right = INT_MAX;
    if(n-1 >= 0)
        left = matrix[m][n-1] + helper(matrix, m-1, n-1, dp);
    if(n+1 < matrix[0].size())    
        right = matrix[m][n+1] + helper(matrix, m-1, n+1, dp);
    int up = matrix[m][n] + helper(matrix, m-1, n, dp);

    return dp[m][n] = min(left, min(up, right));
}

int minFallingPathSum_memo(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    if(m == 1) return matrix[0][0];
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
        dp[0][i] = matrix[0][i];
    }

    for(int i = 1; i < m; i++) {
        for(int j = 0; j < m; j++) {
            int left = INT_MAX;
            if(j-1 >= 0) left = dp[i-1][j-1] + matrix[i][j];

            int up = dp[i-1][j] + matrix[i][j];

            int right = INT_MAX;
            if(j+1 < m) right = dp[i-1][j+1] + matrix[i][j];

            dp[i][j] = min(up, min(left, right));
        }
    }

    for(int i = 0; i < m; i++) {
        mini = min(mini, dp[m-1][i]);
    }

    return mini;
}

int main() {
    vector<vector<int>> matrix1 = {{-19,57},{-40,-5}};
    vector<vector<int>> matrix2 = {{2,1,3},{6,5,4},{7,8,9}};
    // vector<vector<int>> matrix(100, vector<int>(100, 0));
    // for(int i = 0; i < 100; i++) {
    //     matrix[26][i] = -1;
    // }
    cout<<minFallingPathSum_tab(matrix1)<<endl;
    cout<<minFallingPathSum_tab(matrix2)<<endl;
    return 0;
}