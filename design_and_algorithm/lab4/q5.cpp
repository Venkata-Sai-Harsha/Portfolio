#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<pair<int, int>>> adjList;

    Graph(int V) : vertices(V), adjList(V) {}

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        // If the graph is undirected, add the reverse edge as well
        // adjList[v].push_back({u, weight});
    }

    vector<int> dijkstra(int source) {
        vector<int> distance(vertices, numeric_limits<int>::max());
        distance[source] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            int dist_u = pq.top().first;
            pq.pop();

            if (dist_u > distance[u]) {
                // Skip outdated information
                continue;
            }

            for (const auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight_uv = neighbor.second;

                int new_dist_v = distance[u] + weight_uv;

                if (new_dist_v < distance[v]) {
                    distance[v] = new_dist_v;
                    pq.push({new_dist_v, v});
                }
            }
        }

        return distance;
    }
};

int main() {
    // Example usage:
    Graph graph(6);
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 2, 5);
    graph.addEdge(1, 3, 10);
    graph.addEdge(2, 3, 3);
    graph.addEdge(2, 4, 7);
    graph.addEdge(3, 4, 1);
    graph.addEdge(3, 5, 8);
    graph.addEdge(4, 5, 6);

    int source = 0;
    vector<int> distances = graph.dijkstra(source);

    cout << "Shortest distances from source vertex " << source << ":\n";
    for (int i = 0; i < distances.size(); ++i) {
        cout << "To vertex " << i << ": " << distances[i] << "\n";
    }

    return 0;
}