#include<bits/stdc++.h>
using namespace std;

//brute
/*
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    vector<pair<int, int>> zeroes;
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[0].size(); j++){
            if(mat[i][j] == 0) zeroes.push_back({i,j});
        }
    }
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[0].size(); j++){
            int minDist = INT_MAX;
            if(mat[i][j] == 1) {
                for(auto it: zeroes){
                    minDist = min(minDist, (max(it.first, i) - min(it.first, i)) + (max(it.second, j) - min(it.second, j)));
                }
                mat[i][j] = minDist;
            }
        }
    }
    return mat;
}
*/

vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
    queue<pair<int, int>> q;
    int ones = 0;
    for(int i = 0; i < mat.size(); i++) {
        for(int j = 0; j < mat[0].size(); j++){
            if(mat[i][j] == 0) q.push({i, j});
            else ones++;
        }
    }
    vector<pair<int, int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    int dist = 1;
    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++) {
            pair<int, int> cord = q.front();
            q.pop();
            for(auto dir: directions){
                int r = dir.first + cord.first;
                int c = dir.second + cord.second;
                if(r < 0 || r >= mat.size() || c < 0 || c >= mat[0].size()) continue;
                if(mat[r][c] == 1){
                    mat[r][c] = -dist;
                    q.push({r,c});
                }
            }
            cout<<cord.first<<" "<<cord.second<<endl;
        }
        dist++;
    }

    for(int i = 0; i < mat.size(); i++) {
        for(int j = 0; j < mat[0].size(); j++){
            mat[i][j] = -mat[i][j];
        }
    }

    return mat;
}

int main() {
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
    vector<vector<int>> res = updateMatrix(mat);
    for(auto it: res){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}