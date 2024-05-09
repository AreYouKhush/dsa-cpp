#include<bits/stdc++.h>
using namespace std;

bool isBipartitebfs(vector<vector<int>>& graph) {
    vector<int> color(graph.size(), -1);
    for(int i = 0; i < graph.size(); i++){
        if(color[i] == -1){
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                for(auto it: graph[node]){
                    if(color[it] == -1){
                        color[it] = !color[node];
                        q.push(it);
                    }else if(color[it] == color[node]) return false;
                }
            }
        }
    }
    return true;
}

bool dfs(vector<vector<int>>& graph, vector<int>& color, int i, int nodeColor) {
    color[i] = nodeColor;
    for(auto it: graph[i]) {
        if(color[it] == -1) {
            if(dfs(graph, color, it, !nodeColor) == false) {
                return false;
            }
        } else if (color[it] == nodeColor){
            return false;
        }
    }
    return true;
}

bool isBipartitedfs(vector<vector<int>>& graph) {
    vector<int> color(graph.size(), -1);
    for(int i = 0; i < graph.size(); i++) {
        if(color[i] == -1) {
            if(dfs(graph, color, i, 0) == false) return false;
        }
    }
    return true;
}

int main() {
    vector<vector<int>> adj = {{1,2,3},{0,2},{0,1,3},{0,2}};
    cout << isBipartitedfs(adj);
}