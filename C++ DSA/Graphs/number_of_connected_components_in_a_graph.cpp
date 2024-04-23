#include<bits/stdc++.h>
using namespace std;

int find(vector<int>& par, vector<int>& rank, int node){
    int res = node;
    while(res != par[res]) {
        par[res] = par[par[res]];
        res = par[res];
    }
    return res;
}

int unionn(vector<int>& par, vector<int>& rank, int node1, int node2) {
    int p1 = find(par, rank, node1);
    int p2 = find(par, rank, node2);

    if(p1 == p2) return 0;

    if(rank[p2] > rank[p1]){
        par[p1] = p2;
        rank[p2] += rank[p1];
    } else {
        par[p2] = p1;
        rank[p1] += rank[p2];
    }

    return 1;
}

int connectedComponents(vector<vector<int>>& edges, int n) {
    vector<int> par(n);
    for(int i = 0; i < n; i++) par[i] = i;
    vector<int> rank(n, 1);

    int res = n;

    for(auto it: edges) {
        res -= unionn(par, rank, it[0], it[1]);
    }  

    for(int i = 0; i < n; i++){
        cout<<par[i]<<" "<<rank[i]<<endl;
    }

    return res;
}

int main() {
    vector<vector<int>> edges = {{0,1},{1,2},{3,4},{0,2}};
    int n = 5;
    cout<<connectedComponents(edges, n);
}