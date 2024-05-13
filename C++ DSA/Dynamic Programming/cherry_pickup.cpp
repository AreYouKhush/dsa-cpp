#include<bits/stdc++.h>
using namespace std;

int helper2(vector<vector<int>> grid, int m, int n, bool& flag) {
    if(m < 0 || n < 0 || grid[m][n] == -1) return 0;
    if(m == 0 && n == 0) {
        flag = true;
        return grid[0][0];
    }

    int up = grid[m][n] + helper2(grid, m-1, n, flag);
    int left = grid[m][n] + helper2(grid, m, n-1, flag);

    return flag ? max(up, left) : 0;
}

int helper1(vector<vector<int>>& grid, int m, int n, bool& flag) {
    if(m < 0 || n < 0 || grid[m][n] == -1) return 0;
    if(m == 0 && n == 0) {
        flag = true;
        bool flag2 = false;
        return helper2(grid, grid.size() - 1, grid.size() - 1, flag2);
    }

    int temp = grid[m][n];
    if(grid[m][n] == 1) grid[m][n] = 0;
    int up = temp + helper1(grid, m-1, n, flag);
    int left = temp + helper1(grid, m, n-1, flag);
    grid[m][n] = temp;

    return flag ? max(up, left) : 0;
}
// MLE
int cherryPickup_memlimit(vector<vector<int>>& grid) {
    int n = grid.size();
    if(grid[0][0] == -1 || grid[n-1][n-1] == -1) return 0;
    bool flag = false;
    return helper1(grid, n-1, n-1, flag);
}

int helper(vector<vector<int>>& grid, int r1, int c1, int r2, int c2, bool& flag, vector<vector<vector<vector<int>>>>& dp) {

    if(r1 >= grid.size() || c1 >= grid.size() || r2 >= grid.size() || c2 >= grid.size() || grid[r1][c1] == -1 || grid[r2][c2] == -1) return INT_MIN;

    if(r1 == grid.size() - 1 && c1 == grid.size() - 1){
        flag = true;
        return grid[r1][c1];
    }

    if(dp[r1][c1][r2][c2] != INT_MIN) return dp[r1][c1][r2][c2]; 

    int cherries = 0;
    if(r1 == r2 && c1 == c2) cherries += grid[r1][c1];
    else cherries += grid[r1][c1] + grid[r2][c2];

    int bothdown = helper(grid, r1 + 1, c1, r2 + 1, c2, flag, dp);
    int bothright = helper(grid, r1, c1 + 1, r2, c2 + 1, flag, dp);
    int oneright = helper(grid, r1 + 1, c1, r2, c2 + 1, flag, dp);
    int onedown = helper(grid, r1, c1 + 1, r2 + 1, c2, flag, dp);

    cherries += max(max(bothdown, bothright), max(onedown, oneright));
    dp[r1][c1][r2][c2] = cherries;
    return flag ? cherries : 0;
}

// Memoization 
int cherryPickup_memo(vector<vector<int>>& grid) {
    int n = grid.size();
    if(grid[0][0] == -1 || grid[n-1][n-1] == -1) return 0;
    vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, INT_MIN))));
    bool flag = false;
    return helper(grid, 0, 0, 0, 0, flag, dp);
}

int main() {
    vector<vector<int>> grid1 = {{0,1,0,0},{1,1,-1,1},{1,0,-1,0},{1,0,1,0}};
    vector<vector<int>> grid2 = {{0,1,-1,1},{1,-1,-1,1},{1,0,-1,0},{1,0,1,0}};
    vector<vector<int>> grid3 = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    vector<vector<int>> grid4 = {{1,1,-1},{1,-1,1},{-1,1,1}};
    vector<vector<int>> grid5 = {{1,1,0},{1,-1,1},{0,1,0}};
    vector<vector<int>> grid6 = {{1,1}, {1,1}};
    cout<<cherryPickup_memo(grid1)<<endl;
    cout<<cherryPickup_memo(grid2)<<endl;
    cout<<cherryPickup_memo(grid3)<<endl;
    cout<<cherryPickup_memo(grid4)<<endl;
    cout<<cherryPickup_memo(grid5)<<endl;
    cout<<cherryPickup_memo(grid6)<<endl;
    return 0;
}