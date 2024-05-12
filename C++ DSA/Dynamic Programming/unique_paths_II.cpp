#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp) {
    if(m < 0 || n < 0 || m >= grid.size() || n >= grid[0].size() || grid[m][n] == 1) return 0;
    if(m == grid.size() - 1 && n == grid[0].size() - 1) return 1;
    if(dp[m][n] != -1) return dp[m][n];

    return dp[m][n] = dfs(grid, m + 1, n, dp) + dfs(grid, m, n + 1, dp);
}

int uniquePathsWithObstacles_recursive(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return dfs(grid, 0, 0, dp);
}

// Tabulation
int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    if(grid[0][0] == 1 || grid[m-1][n-1] == 1) return 0; 
    vector<int> dp(n);
    dp[0] = 1;
    for(int i = 1; i < n; i++) {
        dp[i] = (grid[0][i]^1) & dp[i-1];
    }
    for(int i = 1; i < m; i++) {
        int prev = 0;
        for(int j = 0; j < n; j++) {
            if(grid[i][j]) dp[j] = 0;
            else dp[j] += prev;
            prev = dp[j];
        }
    }
    return dp[n-1];
}

// Tabulation
int uniquePathsWithObstacles_str(vector<vector<int>>& grid) {
    vector<int> prev(grid[0].size(), 0);
    for(int i = 0; i < grid.size(); i++) {
        vector<int> cur(grid[0].size(), 0);
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] == -1) cur[j] = 0;
            else if(i==0 && j==0) cur[j] = 1;
            else {
                int up = 0, left = 0;
                if(i>0) up = prev[j];
                if(j>0) left = cur[j-1];
                cur[j] = up + left;
            }
         }
         prev = cur;
    }
    return prev[grid[0].size() - 1];
}

int main() {
    vector<vector<int>> obs = {{0,0,1,0},{0,0,1,0}, {1,1,1,0}, {0,0,0,0}};
    cout<<uniquePathsWithObstacles_str(obs)<<endl;
    cout<<uniquePathsWithObstacles(obs);
    return 0;
}