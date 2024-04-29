#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if(image[sr][sc] == color) return image;
    
    queue<pair<int,int>> q;
    q.push({sr, sc});
    int initial = image[sr][sc];
    image[sr][sc] = color;
    vector<pair<int, int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};


    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++){
            pair<int, int> tp = q.front();
            q.pop();
            for(auto dir: directions){
                int r = dir.first + tp.first;
                int c = dir.second + tp.second;
                if(r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != initial) continue;
                image[r][c] = color;
                q.push({r,c});
            }
        }
    }
    return image;
}

int main() {
    vector<vector<int>> image = {{1,1,0,1,1},{1,0,1,1,1},{1,0,1,1,1}};
    vector<vector<int>> res = floodFill(image, 0, 1, 2);
    for(auto it: res){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}