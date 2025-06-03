// Exercise 11.1: BFS and DFS using Adjacency Matrix

#include <iostream>
#include <vector>
#include <queue>
#include <memory>

class WeightedGraph {
private:
    int vertices;
    std::vector<std::vector<int>> adjacencyMatrix;

public:
    explicit WeightedGraph(int vertexCount)
            : vertices(vertexCount), adjacencyMatrix(vertexCount, std::vector<int>(vertexCount, -1)) {}

    void insertEdge(int source, int destination, int weight = 1, bool bidirectional = true) {
        if (source >= 0 && source < vertices && destination >= 0 && destination < vertices) {
            adjacencyMatrix[source][destination] = weight;
            if (bidirectional) {
                adjacencyMatrix[destination][source] = weight;
            }
        }
    }

    void displayMatrix() const {
        std::cout << "Adjacency Matrix:\n";
        for (int row = 0; row < vertices; ++row) {
            for (int col = 0; col < vertices; ++col) {
                std::cout << (adjacencyMatrix[row][col] == -1 ? 0 : adjacencyMatrix[row][col]) << " ";
            }
            std::cout << "\n";
        }
    }

    void breadthFirstSearch(int startVertex) const {
        if (startVertex < 0 || startVertex >= vertices) return;

        std::vector<bool> isVisited(vertices, false);
        std::queue<int> processingQueue;

        isVisited[startVertex] = true;
        processingQueue.push(startVertex);

        std::cout << "BFS starting from node " << startVertex << ": ";

        while (!processingQueue.empty()) {
            int currentVertex = processingQueue.front();
            std::cout << currentVertex << " ";
            processingQueue.pop();

            for (int neighbor = 0; neighbor < vertices; ++neighbor) {
                if (adjacencyMatrix[currentVertex][neighbor] > 0 && !isVisited[neighbor]) {
                    processingQueue.push(neighbor);
                    isVisited[neighbor] = true;
                }
            }
        }
        std::cout << "\n";
    }

    void depthFirstSearch(int startVertex) const {
        if (startVertex < 0 || startVertex >= vertices) return;

        std::vector<bool> isVisited(vertices, false);
        std::cout << "DFS starting from node " << startVertex << ": ";
        performDFS(startVertex, isVisited);
        std::cout << "\n";
    }

private:
    void performDFS(int currentVertex, std::vector<bool>& isVisited) const {
        isVisited[currentVertex] = true;
        std::cout << currentVertex << " ";

        for (int neighbor = 0; neighbor < vertices; ++neighbor) {
            if (adjacencyMatrix[currentVertex][neighbor] > 0 && !isVisited[neighbor]) {
                performDFS(neighbor, isVisited);
            }
        }
    }
};

int main() {
    const int graphSize = 5;
    WeightedGraph graph(graphSize);

    graph.insertEdge(0, 1, 2);
    graph.insertEdge(0, 2, 4);
    graph.insertEdge(1, 2, 1);
    graph.insertEdge(1, 3, 7);
    graph.insertEdge(2, 4, 3);
    graph.insertEdge(3, 4, 1);

    graph.displayMatrix();
    graph.breadthFirstSearch(0);
    graph.depthFirstSearch(0);

    return 0;
}

// Exercise 11.2: Dijkstra’s Algorithm using Adjacency Matrix

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

class ModernGraph {
private:
    int vertices;
    std::vector<std::vector<int>> adjacencyMatrix;

    int findMinDistanceVertex(const std::vector<int>& distances, const std::vector<bool>& visited) const {
        int minDistance = std::numeric_limits<int>::max();
        int minVertex = -1;

        for (int v = 0; v < vertices; ++v) {
            if (!visited[v] && distances[v] <= minDistance) {
                minDistance = distances[v];
                minVertex = v;
            }
        }
        return minVertex;
    }

public:
    explicit ModernGraph(int numVertices) : vertices(numVertices) {
        adjacencyMatrix.resize(vertices, std::vector<int>(vertices, 0));
    }

    void addEdge(int source, int destination, int weight = 1, bool isUndirected = true) {
        if (source >= 0 && source < vertices && destination >= 0 && destination < vertices) {
            adjacencyMatrix[source][destination] = weight;
            if (isUndirected) {
                adjacencyMatrix[destination][source] = weight;
            }
        }
    }

    void calculateShortestPaths(int sourceVertex) const {
        std::vector<int> distances(vertices, std::numeric_limits<int>::max());
        std::vector<bool> visited(vertices, false);

        distances[sourceVertex] = 0;

        for (int count = 0; count < vertices - 1; ++count) {
            int currentVertex = findMinDistanceVertex(distances, visited);

            if (currentVertex == -1) break;

            visited[currentVertex] = true;

            for (int neighbor = 0; neighbor < vertices; ++neighbor) {
                if (!visited[neighbor] &&
                    adjacencyMatrix[currentVertex][neighbor] > 0 &&
                    distances[currentVertex] != std::numeric_limits<int>::max() &&
                    distances[currentVertex] + adjacencyMatrix[currentVertex][neighbor] < distances[neighbor]) {

                    distances[neighbor] = distances[currentVertex] + adjacencyMatrix[currentVertex][neighbor];
                }
            }
        }

        displayShortestPaths(sourceVertex, distances);
    }

private:
    void displayShortestPaths(int source, const std::vector<int>& distances) const {
        std::cout << "Shortest paths from vertex " << source << ":\n";
        std::cout << "Destination\tDistance\n";
        std::cout << "------------------------\n";

        for (int i = 0; i < vertices; ++i) {
            std::cout << i << "\t\t";
            if (distances[i] == std::numeric_limits<int>::max()) {
                std::cout << "INF\n";
            } else {
                std::cout << distances[i] << "\n";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    const int graphSize = 5;
    ModernGraph graph(graphSize);

    // Adding weighted edges to create the graph
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 7);
    graph.addEdge(2, 4, 3);
    graph.addEdge(3, 4, 1);

    // Calculate and display shortest paths from vertex 0
    graph.calculateShortestPaths(0);

    return 0;
}

