#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

void bfs(vector<vector<int>>& graph, int start) {
    int vertices = graph.size();
    vector<bool> visited(vertices, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int current = q.front();
        cout << current << " ";
        q.pop();

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}
int main() {
    vector<vector<int>> graph = {{1, 2}, {0, 2, 3}, {0, 1, 4}, {1, 4}, {2, 3}};
    cout << "BFS traversal starting from node 0: ";
    bfs(graph, 0);
    return 0;
}
