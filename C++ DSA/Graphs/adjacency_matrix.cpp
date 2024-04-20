#include<bits/stdc++.h>
using namespace std;

// n^2 space

int main() {
    int n, m;
    std::cin>>n>>m;
    // Graph stored here
    vector<vector<int>> adj(n+1, vector<int>(m+1, 0));

    for(int i = 0; i < m; i++){
        int u, v;
        std::cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < m+1; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}