#include<bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>>& grid, int row, int c1, int c2, vector<vector<vector<int>>>& dp) {
    if(row >= grid.size() || c1 >= grid[0].size() || c2 >= grid[0].size() || c1 < 0 || c2 < 0) return INT_MIN;
    if(row == grid.size() - 1) {
        if(c1 == c2) return grid[row][c1];
        else return grid[row][c1] + grid[row][c2];
    }
    if(dp[row][c1][c2] != -1) return dp[row][c1][c2];
    if(dp[row][c2][c1] != -1) return dp[row][c2][c1];
    int sum = 0;
    if(c1 == c2) sum += grid[row][c1];
    else sum += (grid[row][c1] + grid[row][c2]);

    vector<pair<int, int>> directions = {{0,0},{-1,0},{1,0},{0,-1},{-1,-1},{1,-1},{0,1},{-1,1},{1,1}};
    int maxi = INT_MIN;
    for(auto dir: directions) {
        maxi = max(maxi, helper(grid, row+1, c1+dir.first, c2+dir.second, dp));
    }
    sum += maxi;
    return dp[row][c1][c2] = dp[row][c2][c1] = sum;
}

int cherryPickup(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
    return helper(grid, 0, 0, grid[0].size() - 1, dp);
}

int main() {
    vector<vector<int>> grid1 = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    vector<vector<int>> grid2 = {{1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6}};

    cout<<cherryPickup(grid1)<<endl;
    cout<<cherryPickup(grid2)<<endl;
    return 0;
}