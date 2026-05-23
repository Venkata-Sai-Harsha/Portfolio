#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int vertex, weight;
};

class CompareNode {
public:
    bool operator()(const Node& a, const Node& b) {
        return a.weight > b.weight;
    }
};

void primMST(vector<vector<Node>>& graph, int vertices) {
    vector<bool> inMST(vertices, false);
    vector<int> key(vertices, INT_MAX);
    vector<int> parent(vertices, -1);

    priority_queue<Node, vector<Node>, CompareNode> pq;
    
    // Start with the first vertex
    int startVertex = 0;
    key[startVertex] = 0;
    pq.push({startVertex, 0});

    while (!pq.empty()) {
        int u = pq.top().vertex;
        pq.pop();

        inMST[u] = true;

        for (const Node& neighbor : graph[u]) {
            int v = neighbor.vertex;
            int weight = neighbor.weight;

            if (!inMST[v] && key[v] > weight) {
                key[v] = weight;
                parent[v] = u;
                pq.push({v, weight});
            }
        }
    }

    cout << "Minimum Spanning Tree using Prim's Algorithm:\n";
    for (int i = 1; i < vertices; ++i) {
        cout << parent[i] << " - " << i << " (" << key[i] << ")\n";
    }
}

int main() {
    // Example usage:
    vector<vector<Node>> graph = {
        {{1, 4}, {7, 8}},
        {{0, 4}, {2, 8}, {7, 11}},
        {{1, 8}, {3, 7}, {5, 4}, {8, 2}},
        {{2, 7}, {4, 9}, {5, 14}},
        {{3, 9}, {5, 10}},
        {{2, 4}, {3, 14}, {4, 10}, {6, 2}},
        {{5, 2}, {7, 1}, {8, 6}},
        {{0, 8}, {1, 11}, {6, 1}, {8, 7}},
        {{2, 2}, {6, 6}, {7, 7}}
    };
    int vertices = 9;

    primMST(graph, vertices);

    return 0;
}
