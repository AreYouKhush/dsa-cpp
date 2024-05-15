#include<bits/stdc++.h>
using namespace std;

int swimInWater(vector<vector<int>>& grid) {
    priority_queue<vector<int>> pq;
    pq.push({-grid[0][0], 0, 0});
    set<pair<int, int>> vis;
    vis.insert({0,0});

    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    while(!pq.empty()) {
        int wave = -pq.top()[0];
        int r = pq.top()[1];
        int c = pq.top()[2];
        pq.pop();

        if(r == grid.size()-1 && c == grid[0].size()-1) return wave;

        for(auto dir: directions) {
            int nr = dir[0] + r;
            int nc = dir[1] + c;
            if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && vis.find({nr, nc}) == vis.end()) {
                vis.insert({nr, nc});
                int maxwave = max(grid[nr][nc], wave);
                pq.push({-maxwave, nr, nc});
            }
        }

    }
    return -1;
}

int main() {
    vector<vector<int>> grid1 = {{0,2},{1,3}};
    vector<vector<int>> grid2 = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    vector<vector<int>> grid3 = {{2,3,5,5,2},{4,3,2,1,5},{1,3,4,5,6},{1,7,1,1,2},{5,9,8,7,6}};
    
    cout<<swimInWater(grid1)<<endl;
    cout<<swimInWater(grid2)<<endl;
    cout<<swimInWater(grid3)<<endl;
    return 0;
}