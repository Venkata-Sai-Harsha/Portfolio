#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<int>> adjacencyMatrix;

    Graph(int V) : vertices(V), adjacencyMatrix(V, vector<int>(V, numeric_limits<int>::max())) {}

    void addEdge(int u, int v, int weight) {
        adjacencyMatrix[u][v] = weight;
        // If the graph is undirected, set the reverse edge as well
        // adjacencyMatrix[v][u] = weight;
    }

    void floydWarshall() {
        for (int k = 0; k < vertices; ++k) {
            for (int i = 0; i < vertices; ++i) {
                for (int j = 0; j < vertices; ++j) {
                    if (adjacencyMatrix[i][k] != numeric_limits<int>::max() &&
                        adjacencyMatrix[k][j] != numeric_limits<int>::max() &&
                        adjacencyMatrix[i][k] + adjacencyMatrix[k][j] < adjacencyMatrix[i][j]) {
                        adjacencyMatrix[i][j] = adjacencyMatrix[i][k] + adjacencyMatrix[k][j];
                    }
                }
            }
        }
    }
};

int main() {
    // Example usage:
    Graph graph(4);
    graph.addEdge(0, 1, 1);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 3, 1);

    graph.floydWarshall();

    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < graph.vertices; ++i) {
        for (int j = 0; j < graph.vertices; ++j) {
            if (graph.adjacencyMatrix[i][j] == numeric_limits<int>::max()) {
                cout << "INF\t";
            } else {
                cout << graph.adjacencyMatrix[i][j] << "\t";
            }
        }
        cout << endl;
    }

    return 0;
}