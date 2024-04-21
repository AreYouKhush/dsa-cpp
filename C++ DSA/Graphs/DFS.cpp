#include<bits/stdc++.h>
using namespace std;

// SC :- O(N) + O(N) + O(N)
// TC :- O(N) + O(2E) for undirected graph
//       O(N) + O(E) for directed graph

void recurDFS(vector<vector<int>>& adj, vector<int>& visited, vector<int>& dfs, int root) {
    if(visited[root] == 1) return;
    visited[root] = 1;
    dfs.push_back(root);
    for(auto it: adj[root]) {
        recurDFS(adj, visited, dfs, it);
    }
}

vector<int> DFS(vector<vector<int>>& adj) {
    vector<int> dfs;
    vector<int> visited(adj.size());
    recurDFS(adj, visited, dfs, 1);
    return dfs;
}

int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        if(u != v)
            adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        cout<<i<<" -----> ";
        for(auto it: adj[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    vector<int> dfs = DFS(adj);

    for(auto it: dfs) {
        cout<<it<<" ";
    }
}