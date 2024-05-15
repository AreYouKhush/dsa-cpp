#include<bits/stdc++.h>
using namespace std;

int matrixScore(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    for(int col = 0; col < n; col++) {
        int cnt = 0;
        for(int row = 0; row < m; row++) {
            if(col == 0 && grid[row][col] == 0) {
                for(int i = 0; i < n; i++) grid[row][i] = !grid[row][i];
            } else if(grid[row][col] == 0) {
                cnt++;
            }
        }
        if(col != 0 && cnt > m/2) {
            for(int row = 0; row < m; row++) {
                grid[row][col] = !grid[row][col];
            }
        }
    }

    int res = 0;
    for(int row = 0; row < m; row++) {
        int num = 0;
        for(int col = 0; col < n; col++) {
            num = num << 1;
            num = num | grid[row][col];
        }
        res += num;
    }

    return res;
}

int main() {
    // vector<vector<int>> grid = {{0,1,1,0}, {0,1,1,1}, {1,0,0,0}};
    // vector<vector<int>> grid = {{0,1,1,1,1}, {1,1,1,1,1}, {0,1,1,1,1}};
    vector<vector<int>> grid = {{0,1,1,1,1}, {1,0,0,0,0}, {1,0,0,0,0}};
    cout<<matrixScore(grid)<<endl;
    for(auto it: grid) {
        for(auto i: it) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}