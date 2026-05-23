#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(vector<vector<int>>& graph, int current, vector<bool>& visited) {
    cout << current << " ";
    visited[current] = true;

    for (int neighbor : graph[current]) {
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited);
        }
    }
}

void dfsTraversal(vector<vector<int>>& graph, int start) {
    int vertices = graph.size();
    vector<bool> visited(vertices, false);
    dfs(graph, start, visited);
}

int main() {
    // Example usage:
    vector<vector<int>> graph = {{1, 2}, {0, 2, 3}, {0, 1, 4}, {1, 4}, {2, 3}};
    cout << "DFS traversal starting from node 0: ";
    dfsTraversal(graph, 0);

    return 0;
}
