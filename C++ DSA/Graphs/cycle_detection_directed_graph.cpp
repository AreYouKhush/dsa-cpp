#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& path, int node) {
    vis[node] = 1;
    path[node] = 1;
    for(auto it: adj[node]){
        if(vis[it] == 0) {
            if(dfs(adj, vis, path, it)) {
                return true;
            }
        }else if(path[it]) {
            return true;
        }
    }
    path[node] = 0;
    return false;
}

bool isCyclic(vector<vector<int>>& adj) {
    vector<int> visited(adj.size(), 0);
    vector<int> path(adj.size(), 0);
    for(int i = 0; i < adj.size(); i++) {
        if(!visited[i] && dfs(adj, visited, path, i)) {
            return true;
        }
    }
    return false;
}

int main() {
    // vector<vector<int>> adj = {{1,2},{3},{3},{}};
    vector<vector<int>> adj = {{1,5},{2,4},{3},{4},{6},{1},{5,7,8},{},{}};
    cout<<isCyclic(adj);
}