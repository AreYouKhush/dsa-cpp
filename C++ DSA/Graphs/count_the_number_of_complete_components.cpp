#include<bits/stdc++.h>
using namespace std;

int countCompleteComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    for(auto it: edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    for(int i = 0; i < adj.size(); i++) {
        cout<<i<<" ----> ";
        for(auto it: adj[i]) {
            cout<<it<<" ";
        }
        cout<<endl;
    }

    vector<int> visited(n, 0);
    int res = 0;

    for(int i = 0; i < n; i++) {
        if(adj[i].size() == 0){
            res++;
            visited[i] = -1;
        }else if(visited[i] == 0){
            queue<int> q;
            q.push(i);
            int minNode = INT_MAX;

            while(!q.empty()) {
                int temp = q.front();
                q.pop();
                visited[temp] = 1;
                minNode = adj[temp].size() < minNode ? adj[temp].size() : minNode;
                for(auto it: adj[temp]) {
                    if(visited[it] == 0) {
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }

            int c = 0;

            for(auto& it: visited) {
                if(it == 1){
                    c++;
                    it = -1;
                }
            }

            if(c-1 == minNode) {
                res++;
            }

        }
    }

    for(auto it: visited){
        cout<<it<<" ";
    }

    return res;
}

int main() {
    vector<vector<int>> edges = {{1,2},{2,3},{3,5},{5,2},{5,1},{1,3}};
    int n = 7;

    cout<<countCompleteComponents(n, edges);
}