#include<bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp) {
    if(m < 0 || n < 0) return INT_MAX;
    if(m == 0 && n == 0) return grid[m][n];
    if(dp[m][n] != -1) return dp[m][n];

    int up = helper(grid, m-1, n, dp);
    int left = helper(grid, m, n-1, dp);

    return dp[m][n] = grid[m][n] + min(up, left);
}
// Memoization
int minPathSum_memo(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return helper(grid, m - 1, n - 1, dp);
}

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) dp[i][j] = grid[i][j];
            else {
                int up = grid[i][j];
                if(i > 0) up += dp[i-1][j];
                else up += 1e9;

                int left = grid[i][j];
                if(j > 0) left += dp[i][j-1];
                else left += 1e9;

                dp[i][j] = min(left, up);
            }
        }
    }
    return dp[m-1][n-1];
}

int main() {
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout<<minPathSum(grid);
    return 0;
}