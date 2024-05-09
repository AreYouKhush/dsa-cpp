#include<bits/stdc++.h>
using namespace std;

bool isCyclic(vector<vector<int>>& adj) {
    vector<int> indegree(adj.size(), 0);
    for(int i = 0; i < adj.size(); i++) {
        for(auto it: adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < adj.size(); i++) {
        if(indegree[i] == 0) q.push(i);
    }

    int count = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        count++;
        for(auto it: adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }

    return count == adj.size() ? false : true;
}

int main() {
    vector<vector<int>> adj = {{1,2},{3},{3},{}};
    // vector<vector<int>> adj = {{1,5},{2,4},{3},{4},{6},{1},{5,7,8},{},{}};
    cout<<isCyclic(adj);
}