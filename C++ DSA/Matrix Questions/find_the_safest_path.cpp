#include<bits/stdc++.h>
using namespace std;

int maximumSafenessFactor(vector<vector<int>>& grid) {
    if(grid[0][0] == 1 || grid[grid.size()-1][grid[0].size()-1] == 1) return 0;
    queue<pair<int, int>> q;
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] == 1) {
                q.push({i, j});
                grid[i][j] = -1;
            }
        }
    }

    vector<pair<int, int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    int distance = 1;
    while(!q.empty()) {
        int n = q.size();
        for(int i = 0; i < n; i++) {
            pair<int, int> coords = q.front();
            q.pop();
            for(auto dir: directions) {
                int r = dir.first + coords.first;
                int c = dir.second + coords.second;
                if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) continue;
                if(grid[r][c] == 0) {
                    grid[r][c] = distance;
                    q.push({r, c});
                }
            }
        }
        distance++;
    }

    priority_queue<vector<int>> pq; // (dist, r, c)
    pq.push({grid[0][0], 0, 0});
    set<pair<int, int>> vis;
    vis.insert({0,0});

    while(!pq.empty()) {
        int dist = pq.top()[0];
        int r = pq.top()[1];
        int c = pq.top()[2];
        pq.pop();

        if(r == grid.size() - 1 && c == grid[0].size() - 1)
            return dist;

        for(auto dir: directions) {
            int nr = r + dir.first;
            int nc = c + dir.second;
            if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && vis.find({nr, nc}) == vis.end()) {
                vis.insert({nr, nc});
                int mindist = min(dist, grid[nr][nc]);
                pq.push({mindist, nr, nc});
            }
        }
    }

    return 0;
}


int main() {
    vector<vector<int>> grid1 = {{1,1,0,1,1},{1,0,1,1,1},{1,0,1,1,1}};
    vector<vector<int>> grid2 = {{0,0,1},{0,0,0},{0,0,0}};
    vector<vector<int>> grid3 = {{0,0,0,1},{0,0,0,0},{0,0,0,0},{1,0,0,0}};
    vector<vector<int>> grid4 = {{0,0,0,1},{0,1,0,0},{0,1,0,0},{1,0,0,0}};
    
    cout<<maximumSafenessFactor(grid1)<<endl;
    cout<<maximumSafenessFactor(grid2)<<endl;
    cout<<maximumSafenessFactor(grid3)<<endl;
    cout<<maximumSafenessFactor(grid4)<<endl;

    return 0;
}