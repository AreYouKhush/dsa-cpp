#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& land, int i, int j, int& x, int& y){
    if(i >= land.size() || j >= land[0].size()) return;
    if(land[i][j] == 0 || land[i][j] == -1) return;

    land[i][j] *= -1;
    x = max(x, i);
    y = max(y, j);

    dfs(land, i+1, j, x, y);
    dfs(land, i, j+1, x, y);
}

vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    vector<vector<int>> ans;
    int count = 1;
    for(int i = 0; i < land.size(); i++){
        vector<int> coords;
        for(int j = 0; j < land[0].size(); j++){
            if(land[i][j] == 1){
                coords.push_back(i);
                coords.push_back(j);
                int x = i, y = j;
                dfs(land, i, j, x, y);
                coords.push_back(x);
                coords.push_back(y);
            }
            if(coords.size() > 0)
                ans.push_back(coords);
                coords.clear();
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {{0,1,1,0},{0,1,1,0},{1,0,0,1},{1,0,0,1}};
    vector<vector<int>> ans = findFarmland(matrix);
    cout<<"\n";
    for(auto it: ans){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}