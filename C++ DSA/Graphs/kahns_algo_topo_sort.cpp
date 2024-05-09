#include<bits/stdc++.h>
using namespace std;

vector<int> toposort(vector<vector<int>>& adj) {
    vector<int> indegree(adj.size(), 0);
    for(int i = 0; i < adj.size(); i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < adj.size(); i++){
        if(indegree[i] == 0) q.push(i);
    }   

    // O(V + V)
    vector<int> topo;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it: adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return topo;
}

int main() {
    vector<vector<int>> adj = {{},{},{3},{1},{0,1},{0,2}};
    vector<int> topo = toposort(adj);
    for(int it: topo){
        cout<<it<<" ";
    }
}