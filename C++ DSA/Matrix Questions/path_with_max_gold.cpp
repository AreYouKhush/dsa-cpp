#include<bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>>& grid, int i, int j) {
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid.size()) return 0;
    if(grid[i][j] == 0) return 0;

    int temp = grid[i][j];
    grid[i][j] = 0;
    int up = temp + helper(grid, i-1, j);
    int left = temp + helper(grid, i, j-1);
    int down = temp + helper(grid, i+1, j);
    int right = temp + helper(grid, i, j+1);
    grid[i][j] = temp;

    return max(max(up, left), max(down, right));
}

int getMaximumGold(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int maxi = INT_MIN;

    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            maxi = max(maxi, helper(grid, i, j));
        }
    }

    return maxi;
}

int main() {
    vector<vector<int>> grid1 = {{0,6,0},{5,8,7},{0,9,0}};
    vector<vector<int>> grid2 = {{0 ,0 ,34,0,5 ,0 ,7,0,0 ,0 },
                                 {0 ,0 ,0 ,0,21,0 ,0,0,0 ,0 },
                                 {0 ,18,0 ,0,8 ,0 ,0,0,4 ,0 },
                                 {0 ,0 ,0 ,0,0 ,0 ,0,0,0 ,0 },
                                 {15,0 ,0 ,0,0 ,22,0,0,0 ,21},
                                 {0 ,0 ,0 ,0,0 ,0 ,0,0,0 ,0 },
                                 {0 ,7 ,0 ,0,0 ,0 ,0,0,38,0 }};
    cout<<getMaximumGold(grid1)<<endl;
    cout<<getMaximumGold(grid2)<<endl;
    return 0;
}