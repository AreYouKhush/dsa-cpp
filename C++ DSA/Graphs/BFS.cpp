#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> BFS(vector<vector<int>>& adj, int root){
    vector<int> visited(adj.size(), 0);
    vector<vector<int>> bfs;
    queue<int> q;
    q.push(root);
    visited[root] = 1;
    q.push(-1);
    vector<int> level;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        if(temp == -1){
            bfs.push_back(level);
            level.clear();
            if(!q.empty()){
                q.push(-1);
            }
        }else{
            level.push_back(temp);
            for(auto it: adj[temp]){
                if(visited[it] == 0){
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    return bfs;
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

    vector<vector<int>> bfs = BFS(adj, 5);

    for(auto it: bfs){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

// 10 16 5 4 5 2 4 2 4 1 6 1 2 3 2 6 2 7 6 3 3 8 3 7 8 9 9 7 9 10 7 10 6 8