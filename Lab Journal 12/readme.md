This project contains two graph-based exercises focused on common graph algorithms using adjacency matrix representation:

Exercise 11.1 demonstrates basic graph creation, display, and traversal using Breadth-First Search (BFS) and Depth-First Search (DFS).

Exercise 11.2 implements Dijkstra’s Algorithm to find the shortest paths from a source node to all other nodes in the graph.

🔹 Exercise 11.1 – BFS and DFS Traversals Purpose: To create a weighted undirected graph using an adjacency matrix and perform two types of graph traversals:

BFS (Breadth-First Search): Explores neighbors level by level using a queue.

DFS (Depth-First Search): Explores as far as possible along each branch before backtracking, using recursion.

Key Features: Graph initialized with all values as -1 (meaning no connection).

Edges added with weights.

BFS and DFS implemented to visit all reachable nodes starting from a given vertex.

Matrix printed in a readable format showing edge weights or 0 where no connection exists.

🔹 Exercise 11.2 – Dijkstra’s Algorithm Purpose: To implement Dijkstra’s Algorithm for finding the shortest distance from a single source node to all other nodes in a weighted graph.

Key Features: Graph created using an adjacency matrix initialized with 0s (no edge).

Allows adding weighted undirected edges.

Implements Dijkstra’s logic using:

An array to store shortest distances.

A boolean array to track visited nodes.

After computation, displays the shortest distance from the source node to every other node