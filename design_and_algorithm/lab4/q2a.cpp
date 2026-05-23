#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

bool containsCycleBFS(vector<vector<int>>& graph) {
    int vertices = graph.size();
    vector<bool> visited(vertices, false);

    for (int start = 0; start < vertices; ++start) {
        if (!visited[start]) {
            queue<int> q;
            unordered_set<int> currentCycleSet;

            q.push(start);
            visited[start] = true;
            currentCycleSet.insert(start);

            while (!q.empty()) {
                int current = q.front();
                q.pop();

                for (int neighbor : graph[current]) {
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = true;
                        currentCycleSet.insert(neighbor);
                    } else if (currentCycleSet.find(neighbor) != currentCycleSet.end()) {
                        // The neighbor is already in the current cycle set
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    // Example usage:
    vector<vector<int>> graph = {{1, 2}, {0, 2, 3}, {0, 1, 4}, {1, 4}, {2, 3}};
    
    if (containsCycleBFS(graph)) {
        cout << "The graph contains a cycle (BFS)." << endl;
    } else {
        cout << "The graph does not contain a cycle (BFS)." << endl;
    }

    return 0;
}