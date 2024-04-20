## Graphs in Computer Science

Graphs are a fundamental data structure in computer science used to represent relationships between pairs of objects. A graph consists of a set of vertices (also called nodes) and a set of edges (also called arcs or links) that connect pairs of vertices. Each edge connects two vertices and may have an associated weight or cost.

### Types of Graphs

1. **Directed Graphs (Digraphs):** In a directed graph, each edge has a direction associated with it, indicating a one-way relationship between vertices.

2. **Undirected Graphs:** In an undirected graph, edges have no direction, and the relationship between vertices is bidirectional.

3. **Weighted Graphs:** In a weighted graph, each edge has a weight or cost associated with it, representing some quantitative value such as distance, time, or cost.

4. **Cyclic and Acyclic Graphs:** A graph containing at least one cycle (a path that starts and ends at the same vertex) is called cyclic. A graph without any cycles is called acyclic.

### Applications of Graphs

Graphs are used in various applications, including:

- **Networks:** Graphs are used to model networks such as social networks, transportation networks, and computer networks.

- **Routing Algorithms:** Graphs are used in routing algorithms to find the shortest path or optimal route between nodes.

- **Data Structures:** Graphs serve as the basis for implementing various data structures like trees, heaps, and associative arrays.

- **Circuit Design:** Graphs are used to model circuit connections in electrical engineering and computer hardware design.

- **Recommendation Systems:** Graphs are used to model user-item relationships in recommendation systems, where vertices represent users and items, and edges represent interactions or preferences.

- **Dependency Resolution:** Graphs are used in dependency resolution systems to represent dependencies between software components or modules.

### Graph Representation

Graphs can be represented using various data structures, including:

- **Adjacency Matrix:** A 2D array where the entry at row \( i \) and column \( j \) represents the presence or absence of an edge between vertices \( i \) and \( j \).

- **Adjacency List:** A collection of lists or arrays where each list/array corresponds to a vertex and contains the vertices adjacent to it.

- **Edge List:** A list of tuples representing edges, where each tuple contains the IDs of the vertices connected by the edge and optionally the weight of the edge.

Understanding graphs and their representations is crucial for solving a wide range of problems efficiently in computer science and related fields.

# Formulas for Graph Properties

## General Formulas:

1. **Number of Vertices (\(V\)):** The total number of vertices in the graph.
   - Formula: \(V = \text{Number of vertices}\)

2. **Number of Edges (\(E\)):** The total number of edges in the graph.
   - Formula: \(E = \text{Number of edges}\)

## Undirected Graphs:

1. **Degree of a Vertex (\(d(v)\)):** The number of edges incident to a vertex.
   - Formula: \(d(v) = \text{Number of edges incident to vertex } v\)

2. **Total Degree of the Graph (\(2E\)):** The sum of degrees of all vertices in an undirected graph.
   - Formula: \(2E = \sum_{v \in V} d(v)\)

3. **Number of Edges (\(E\)) in terms of Vertex Degrees:**
   - Formula: \(E = \frac{1}{2} \sum_{v \in V} d(v)\)

## Directed Graphs (Digraphs):

1. **In-Degree of a Vertex (\(d_{\text{in}}(v)\)):** The number of edges coming into a vertex.
   - Formula: \(d_{\text{in}}(v) = \text{Number of edges coming into vertex } v\)

2. **Out-Degree of a Vertex (\(d_{\text{out}}(v)\)):** The number of edges going out from a vertex.
   - Formula: \(d_{\text{out}}(v) = \text{Number of edges going out from vertex } v\)

3. **Total In-Degree of the Graph:**
   - Formula: \(\sum_{v \in V} d_{\text{in}}(v)\)

4. **Total Out-Degree of the Graph:**
   - Formula: \(\sum_{v \in V} d_{\text{out}}(v)\)

## Weighted Graphs:

1. **Total Weight of the Graph:** The sum of weights of all edges in the graph.
   - Formula: \(\sum_{e \in E} \text{Weight of edge } e\)

2. **Average Weight of the Graph:** The average weight of all edges in the graph.
   - Formula: \(\text{Average Weight} = \frac{\sum_{e \in E} \text{Weight of edge } e}{\text{Number of edges}}\)

## Complete Graphs:

1. **Number of Edges (\(E\)):** In a complete graph with \(n\) vertices, every vertex is connected to every other vertex.
   - Formula: \(E = \frac{n(n-1)}{2}\)

## Bipartite Graphs:

1. **Bipartition Property:** A graph is bipartite if its vertices can be divided into two disjoint sets such that no two vertices within the same set are adjacent.
   - Formula: None

## Trees:

1. **Number of Edges (\(E\)):** In a tree with \(n\) vertices, there are \(n-1\) edges.
   - Formula: \(E = n - 1\)

2. **Height of a Tree:** The number of edges on the longest downward path between the root and a leaf.
   - Formula: Height = Maximum depth of any node in the tree

3. **Depth of a Node:** The length of the path from the root to that node.
   - Formula: Depth = Number of edges from the root to the node

4. **Number of Leaves:** The number of nodes in the tree with no children.
   - Formula: Number of Leaves = Number of vertices with degree 1

5. **Internal Nodes:** Nodes in the tree that are not leaves.
   - Formula: Internal Nodes = Number of vertices - Number of Leaves


# Connected Components in Graph

In graph theory, a connected component of an undirected graph is a subgraph in which every pair of vertices is connected to each other by paths, and which is connected to no additional vertices in the supergraph. In simpler terms, a connected component is a group of vertices within a graph such that there is a path between every pair of vertices in the group, and no path exists between any vertex in the group and any vertex outside the group.

## Properties of Connected Components:

1. **Maximality:** A connected component is maximal in the sense that it cannot be extended by adding more vertices and edges while maintaining connectivity.

2. **Vertex Connectivity:** In a connected component, every vertex can be reached from every other vertex by traversing edges in the component.

3. **Graph Connectivity:** The entire graph can be partitioned into connected components, and each vertex belongs to exactly one connected component.

## Finding Connected Components:

### Depth-First Search (DFS):

DFS is commonly used to find connected components in a graph:

1. **Algorithm:**
   - Start DFS traversal from an arbitrary vertex.
   - Explore as far as possible along each branch before backtracking.
   - Mark each visited vertex as belonging to the current connected component.
   - Repeat the process until all vertices are visited.

2. **Implementation:**
   - Initialize a list to store connected components.
   - While there are unvisited vertices:
     - Perform DFS from an unvisited vertex.
     - Add all visited vertices to the current connected component.
     - Add the connected component to the list.

### Breadth-First Search (BFS):

BFS can also be used to find connected components:

1. **Algorithm:**
   - Start BFS traversal from an arbitrary vertex.
   - Explore neighbors of each vertex at the current level before moving to the next level.
   - Mark each visited vertex as belonging to the current connected component.
   - Repeat the process until all vertices are visited.

2. **Implementation:**
   - Initialize a list to store connected components.
   - While there are unvisited vertices:
     - Perform BFS from an unvisited vertex.
     - Add all visited vertices to the current connected component.
     - Add the connected component to the list.
