This repository contains two C++ implementations of a weighted graph data structure:

Weighted Graph using Adjacency Matrix Represents the graph using a 2D matrix.
Each cell (i, j) stores the weight of the edge between vertex i and vertex j.

If no edge exists, the cell value is 0.

Suitable for dense graphs.

Supports adding undirected weighted edges and printing the adjacency matrix.

Weighted Graph using Adjacency List Represents the graph using an adjacency list.
Each vertex stores a list of pairs (neighbor, weight) representing its edges.

More space-efficient for sparse graphs.

Supports adding undirected weighted edges and printing the adjacency list.