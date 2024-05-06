#include<bits/stdc++.h>
using namespace std;

bool isCyclicDisconntected(vector<vector<int>>& adj, int vertices) {

}

int main() {
	int vertices, edges;
    cin>>vertices>>edges;
	vector<vector<int>> adj(vertices);

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

    if (isCyclicDisconntected(adj, vertices))
        cout << "Yes";
    else
        cout << "No";

	return 0; 
}