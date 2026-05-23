#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool dfsDetectCycle(vector<vector<int>>& graph, int current, vector<bool>& visited, int parent) {
    visited[current] = true;

    for (int neighbor : graph[current]) {
        if (!visited[neighbor]) {
            if (dfsDetectCycle(graph, neighbor, visited, current)) {
                return true;
            }
        } else if (neighbor != parent) {
            // The neighbor is visited and not the parent, indicating a cycle
            return true;
        }
    }

    return false;
}

bool containsCycleDFS(vector<vector<int>>& graph) {
    int vertices = graph.size();
    vector<bool> visited(vertices, false);

    for (int start = 0; start < vertices; ++start) {
        if (!visited[start] && dfsDetectCycle(graph, start, visited, -1)) {
            return true;
        }
    }

    return false;
}

int main() {
    // Example usage:
    vector<vector<int>> graph = {{1, 2}, {0, 2, 3}, {0, 1, 4}, {1, 4}, {2, 3}};

    if (containsCycleDFS(graph)) {
        cout << "The graph contains a cycle (DFS)." << endl;
    } else {
        cout << "The graph does not contain a cycle (DFS)." << endl;
    }

    return 0;
}