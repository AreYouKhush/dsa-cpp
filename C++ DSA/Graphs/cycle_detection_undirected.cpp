#include<bits/stdc++.h>
using namespace std;

bool isThereCycleBFS(vector<vector<int>>& adj) {
    vector<int> vis(adj.size(), 0);
    for(int i = 0; i < adj.size(); i++){
        if(!vis[i]){
            vector<int> visited(adj.size(), 0);
            queue<pair<int, int>> q;
            int src = i;
            q.push({src, -1});
            visited[src] = 1;
            while(!q.empty()){
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();
                for(auto neigh: adj[node]){
                    if(!visited[neigh]){
                        visited[neigh] = 1;
                        q.push({neigh, node});
                    }else if(parent != neigh){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool detectdfs(vector<vector<int>>& adj, vector<int>& visited, int node, int parent){
    visited[node] = 1;
    for(auto it: adj[node]){
        cout<<it<<" "<<parent<<endl;
        if(!visited[it]){
            if(detectdfs(adj, visited, it, node) == true)
                return true;
        }
        else if(it != parent) return true;
    }
    return false;
}

bool isThereCycleDFS(vector<vector<int>>& adj) {
    vector<int> visited(adj.size(), 0);
    for(int i = 1; i < adj.size(); i++){
        vector<int> vis(adj.size(), 0);
        if(detectdfs(adj, vis, i, -1)){
            return true;
        }
    }
    return false;
}

int main() {
	int vertices, edges;
    cin>>vertices>>edges;
	vector<vector<int>> adj(vertices);

    // 8 7 1 2 1 3 2 5 3 4 3 6 5 7 6 7   
    // 6 4 1 2 3 4 3 5 4 5
    for(int i = 0 ; i < edges; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    for(int i = 0; i < adj.size(); i++){
        cout<<i<<" ---> ";
        for(auto it: adj[i]){
            cout<<it<<" ";
        }
        cout<<"\n";
    }

    // if (isThereCycleBFS(adj))
    if(isThereCycleDFS(adj))
        cout << "Yes";
    else
        cout << "No";

	return 0; 
}