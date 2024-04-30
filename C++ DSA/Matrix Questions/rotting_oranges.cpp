#include<bits/stdc++.h>
using namespace std;

// int orangesRotting(vector<vector<int>>& grid) {
//     int clock = 2;
//     bool flag = true;
//     bool twoFlag = true;
//     int i = 5;
//     while(flag) {
//         clock++;
//         flag = false;
//         int cnt = 0;
//         int twocnt = 0;
//         for(int i = 0; i < grid.size(); i++) {
//             for(int j = 0; j < grid[0].size(); j++) {
//                 if(twoFlag){
//                     if(i > 0 && grid[i-1][j] == 2) cnt++;
//                     if(j > 0 && grid[i][j-1] == 2) cnt++;
//                     if(i < grid.size() - 1 && grid[i+1][j] == 2) cnt++;
//                     if(j < grid[0].size() - 1 && grid[i][j+1] == 2) cnt++;
//                     if(cnt == 0) return -1;
//                     else twoFlag = false;
//                 }
//                 if(grid[i][j] == 1) {
//                     if(i > 0 && grid[i-1][j] == clock-1) grid[i][j] = clock, twocnt++;
//                     else if(j > 0 && grid[i][j-1] == clock-1) grid[i][j] = clock, twocnt++;
//                     else if(i < grid.size() - 1 && grid[i+1][j] == clock-1) grid[i][j] = clock, twocnt++;
//                     else if(j < grid[0].size() - 1 && grid[i][j+1] == clock-1) grid[i][j] = clock, twocnt++;
//                     flag = true;
//                     if(twocnt == 0) return -1;
//                 }
//             }
//         }
//     }
//     for(int i = 0; i < grid.size(); i++) {
//         for(int j = 0; j < grid[0].size(); j++) {
//             cout<<grid[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
//     return clock-3;
// }

int orangesRotting(vector<vector<int>>& grid){
    int time = 0;
    int fresh = 0;
    queue<pair<int,int>> q;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == 1) fresh++;
            else if(grid[i][j] == 2) q.push({i,j});
        }
    }

    vector<pair<int, int>> direction = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    while(!q.empty() && fresh > 0) {
        int n = q.size();
        for(int i = 0; i < n; i++){
            pair<int, int> cord = q.front();
            q.pop();
            for(auto dir: direction){
                int r = dir.first + cord.first;
                int c = dir.second + cord.second;
                if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != 1) continue;
                grid[r][c] = 2;
                q.push({r,c});
                fresh--;
            }
        }
        time++;
    }
    return fresh == 0 ? time : -1;
}

int main() {
    vector<vector<int>> grid = {{0,1,1,0},{1,2,0,1},{0,1,2,1},{1,1,0,0}};
    // vector<vector<int>> grid = {{1},{1},{1},{1}};
    cout<<orangesRotting(grid);
}