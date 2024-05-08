#include<bits/stdc++.h>
using namespace std;

// It exists on DAG - Directed Acyclic Graph
// In computer science, a topological sort or topological ordering of a directed graph is a linear ordering of its vertices such that for every directed edge from vertex u to vertex v, u comes before v in the ordering.

/*

Topological Sorting

1. Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering.
2. So, To find the Topological sorting for a graph, we just have to find in-degrees of each vertex and order the nodes from least in-degree to the highest.
3. Topological Sorting for a graph is not possible if the graph is not a DAG.

2 Methods to solve this-

1. Using DFS Based Algorithm
2. Using Kahn's BFS Based Algorithm

Topological Sorting using DFS Based Algorithm

Algorithm:

1.We can modify DFS to find Topological Sorting of a graph. In DFS, we start from a vertex, we first print it and then recursively call DFS for its adjacent vertices.
2. In topological sorting, we use a temporary stack. We don’t print the vertex immediately, we first recursively call topological sorting for all its adjacent vertices, then push it to a stack.
3. Finally, print contents of the stack.
4. Note that a vertex is pushed to stack only when all of its adjacent vertices (and their adjacent vertices and so on) are already in the stack.

Topological Sorting using Kahn's BFS Based Algorithm

The approach is based on the below fact that, A DAG G has at least one vertex with in-degree 0 and one vertex with out-degree 0.

Algorithm:

1. Compute in-degree (number of incoming edges) for each of the vertex present in the DAG and initialize the count of visited nodes as 0.
2. Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)
3. Remove a vertex from the queue (Dequeue operation) and then.
    I. Increment count of visited nodes by 1.
    II. Decrease in-degree by 1 for all its neighbouring nodes.
    III. If in-degree of a neighbouring nodes is reduced to zero, then add it to the queue.
4. Repeat Step 3 until the queue is empty.
5. If count of visited nodes is not equal to the number of nodes in the graph then the topological sort is not possible for the given graph.

How to find in-degree of each node?
There are 2 ways to calculate in-degree of every vertex-

1. Take an in-degree array which will keep track of traverse the array of edges and simply increase the counter of the destination node by 1.
2. Traverse the list for every node and then increment the in-degree of all the nodes connected to it by 1.

*/
void dfs(vector<vector<int>>& graph, int node, stack<int>& st, vector<bool>& visited){
    visited[node] = true;
    for(auto it: graph[node]){
        if(!visited[it]) {
            dfs(graph, it, st, visited);
        }
    }
    st.push(node);
}

vector<int> toposort(vector<vector<int>>& graph){
    stack<int> st;
    vector<bool> visited(graph.size(), false);
    for(int i = 0; i < graph.size(); i++){
        if(!visited[i]){
            dfs(graph, i, st, visited);
        }
    }

    vector<int> res;
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }

    return res;
}

int main() {
    vector<vector<int>> adj = {{},{},{3},{1},{0,1},{0,2}};
    vector<int> topo = toposort(adj);
    for(int it: topo){
        cout<<it<<" ";
    }
}