#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, vector<pair<int, int>>& vec, int row0, int col0){
        vis[row][col] = 1;
        vec.push_back({row - row0, col - col0});
        
        vector<pair<int, int>> direction = {{0,1},{0,-1},{-1,0},{1,0}};
        
        for(auto it: direction){
            int nrow = it.first + row;
            int ncol = it.second + col;
            if(nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow, ncol, vis, grid, vec, row0, col0);
            }
        }
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1) {
                    vector<pair<int, int>> vec;
                    dfs(i, j, vis, grid, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout<<obj.countDistinctIslands(grid)<<endl;
    }
}