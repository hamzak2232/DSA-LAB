// Adjacency Matrix (Weighted, Undirected Graph)

#include <iostream>
#include <vector>
using namespace std;

class WeightedAdjacencyMatrix {
private:
    int numVertices;
    vector<vector<int>> matrix;

public:
    WeightedAdjacencyMatrix(int vertexCount) : numVertices(vertexCount) {
        matrix.assign(numVertices, vector<int>(numVertices, 0));
    }

    void insertEdge(int source, int destination, int weight) {
        matrix[source][destination] = weight;
        matrix[destination][source] = weight; // Bidirectional edge
    }

    void displayMatrix() {
        cout << "Weighted Adjacency Matrix:\n";
        for (int row = 0; row < numVertices; row++) {
            for (int col = 0; col < numVertices; col++) {
                cout << matrix[row][col] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    WeightedAdjacencyMatrix graph(4);

    graph.insertEdge(0, 1, 10);
    graph.insertEdge(0, 2, 5);
    graph.insertEdge(1, 2, 2);
    graph.insertEdge(2, 3, 1);

    graph.displayMatrix();

    return 0;
}

// Adjacency List (Weighted, Undirected Graph)

#include <iostream>
#include <vector>
using namespace std;

class WeightedGraphList {
    int V; // Number of vertices
    vector<vector<pair<int, int>>> adjList; // Vector of pairs: neighbor and weight

public:
    // Constructor
    WeightedGraphList(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    // Add edge between vertices u and v with weight w
    void addEdge(int u, int v, int w) {
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w}); // For undirected graph
    }

    // Display the adjacency list representation
    void printGraph() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (const auto &edge : adjList[i]) {
                cout << "(" << edge.first << ", " << edge.second << ") ";
            }
            cout << "\n";
        }
    }
};

int main() {
    WeightedGraphList graph(4);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 5);
    graph.addEdge(1, 2, 2);
    graph.addEdge(2, 3, 1);

    graph.printGraph();

    return 0;
}

//