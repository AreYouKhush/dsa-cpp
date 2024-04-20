#include<bits/stdc++.h>
using namespace std;

// SC :- O(2E) For Undirected graphs
// SC :- O(E) For Directed graphs
int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);

    for(int i = 0; i < m; i++){
        int u, v;
        // u ----> v
        cin>>u>>v;
        adj[u].push_back(v);
        // if undirected use the below line as well
        // adj[v].push_back(u);
    }

    for(int i = 1; i < n+1; i++){
        cout<<i<<" -> ";
        for(auto it: adj[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    return 0;
}