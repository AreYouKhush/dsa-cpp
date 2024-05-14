#include<bits/stdc++.h>
using namespace std;

using ll = long long int;
ll MOD = (1e9 + 7);
ll helper(vector<vector<int>>& grid, int k, int m, int n, ll sum, vector<vector<vector<ll>>>& dp) {
    if(m < 0 || n < 0) return 0;
    if(m == 0 && n == 0) return ((sum + grid[m][n]) % k) == 0;
    if(dp[m][n][sum] != -1) return dp[m][n][sum] % MOD;
    
    ll up = helper(grid, k, m-1, n, (sum + grid[m][n]) % k, dp) % MOD;
    ll left = helper(grid, k, m, n-1, (sum + grid[m][n]) % k, dp) % MOD;

    return dp[m][n][sum] = (up + left) % MOD;
}

int numberOfPaths(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<ll>>> dp(m, vector<vector<ll>>(n, vector<ll>(k+1, -1)));
    return helper(grid, k, m-1, n-1, 0, dp);
}

int main() {
    vector<vector<int>> grid1 = {{5,2,4},{3,0,5},{0,7,2}};
    vector<vector<int>> grid2 = {{0,0}};
    vector<vector<int>> grid3 = {{7,3,4,9},{2,3,6,2},{2,3,7,0}};

    cout<<numberOfPaths(grid1, 3)<<endl;
    cout<<numberOfPaths(grid2, 5)<<endl;
    cout<<numberOfPaths(grid3, 1)<<endl;
    return 0;
}