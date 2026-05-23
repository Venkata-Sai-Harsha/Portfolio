#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<int>> adjList;
    vector<vector<int>> reverseAdjList;

    Graph(int V) : vertices(V), adjList(V), reverseAdjList(V) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        reverseAdjList[v].push_back(u);
    }

    void dfsFirstPass(int v, vector<bool>& visited, stack<int>& stack) {
        visited[v] = true;

        for (int neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                dfsFirstPass(neighbor, visited, stack);
            }
        }

        stack.push(v);
    }

    void dfsSecondPass(int v, vector<bool>& visited, unordered_set<int>& component) {
        visited[v] = true;
        component.insert(v);

        for (int neighbor : reverseAdjList[v]) {
            if (!visited[neighbor]) {
                dfsSecondPass(neighbor, visited, component);
            }
        }
    }

    vector<unordered_set<int>> kosarajuSCC() {
        stack<int> stack;
        vector<bool> visited(vertices, false);

        // First pass: Fill stack with vertices in finishing time order
        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                dfsFirstPass(i, visited, stack);
            }
        }

        // Reverse the graph for the second pass
        reverseGraph();

        // Reset visited array
        fill(visited.begin(), visited.end(), false);

        vector<unordered_set<int>> stronglyConnectedComponents;

        // Second pass: Process vertices in descending order of finishing times
        while (!stack.empty()) {
            int v = stack.top();
            stack.pop();

            if (!visited[v]) {
                unordered_set<int> component;
                dfsSecondPass(v, visited, component);
                stronglyConnectedComponents.push_back(component);
            }
        }

        return stronglyConnectedComponents;
    }

private:
    void reverseGraph() {
        swap(adjList, reverseAdjList);
    }
};

int main() {
    // Example usage:
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);

    vector<unordered_set<int>> stronglyConnectedComponents = graph.kosarajuSCC();

    cout << "Strongly Connected Components:\n";
    for (const auto& component : stronglyConnectedComponents) {
        for (int vertex : component) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}