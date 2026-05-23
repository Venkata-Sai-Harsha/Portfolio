#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<int>> adjList;

    Graph(int V) : vertices(V), adjList(V) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void topologicalSortDFS(int v, vector<bool>& visited, stack<int>& order) {
        visited[v] = true;

        for (int neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                topologicalSortDFS(neighbor, visited, order);
            }
        }

        order.push(v);
    }

    vector<int> topologicalSort() {
        vector<int> linearOrder;
        stack<int> order;
        vector<bool> visited(vertices, false);

        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                topologicalSortDFS(i, visited, order);
            }
        }

        // Pop elements from the stack to get the linear order
        while (!order.empty()) {
            linearOrder.push_back(order.top());
            order.pop();
        }

        return linearOrder;
    }
};

int main() {
    // Example usage:
    Graph graph(6);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);

    vector<int> linearOrder = graph.topologicalSort();

    cout << "Topological Sorting Order:\n";
    for (int vertex : linearOrder) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}