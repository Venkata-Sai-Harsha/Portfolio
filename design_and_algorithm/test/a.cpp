//directed graph bfs
/*#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

// Function to perform BFS starting from vertex A
void bfsFromA(unordered_map<char, vector<char>>& graph, char startVertex) {
    queue<char> q;
    unordered_set<char> visited;

    q.push(startVertex);
    visited.insert(startVertex);

    while (!q.empty()) {
        char currentVertex = q.front();
        cout << currentVertex;
        q.pop();

        for (char neighbor : graph[currentVertex]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
}

int main() {
    unordered_map<char, vector<char>> graph;

    // Sample input edges
    vector<pair<char, char>> edges = {{'A', 'B'}, {'A', 'C'}, {'B', 'C'}, {'C', 'D'}, {'C', 'E'}, {'A', 'E'}, {'B', 'E'}, {'B', 'D'}};

    // Build the graph
    for (auto& edge : edges) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);  // Assuming the graph is undirected
    }

    // Perform BFS from vertex A
    cout << "BFS traversal from vertex A: ";
    bfsFromA(graph, 'A');
    cout << endl;


        int sumFreq = left->freq + right->freq;
        Node* newNode = new Node('\0', sumFreq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Print Huffman codes
    Node* root = pq.top();
    // TODO: Implement code generation logic to print Huffman codes
}

int main() {
    string text = "Hello, World!";
    buildHuffmanTree(text);
    return 0;
}
    return 0;
}*/




// undirected graph bfs
// directed dfs


/*#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Function to perform DFS starting from vertex A
void dfsFromA(unordered_map<char, vector<char>>& graph, char startVertex, unordered_set<char>& visited) {
    cout << startVertex;
    visited.insert(startVertex);

    for (char neighbor : graph[startVertex]) {
        if (visited.find(neighbor) == visited.end()) {
            dfsFromA(graph, neighbor, visited);
        }
    }
}

int main() {
    unordered_map<char, vector<char>> graph;

    // Sample input edges
    vector<pair<char, char>> edges = {{'A', 'B'}, {'A', 'C'}, {'B', 'C'}, {'C', 'D'}, {'C', 'E'}, {'A', 'E'}, {'B', 'E'}, {'B', 'D'}};

    // Build the graph
    for (auto& edge : edges) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);  // Assuming the graph is undirected
    }

    // Perform DFS from vertex A
    cout << "DFS traversal from vertex A: ";
    unordered_set<char> visited;
    dfsFromA(graph, 'A', visited);
    cout << endl;

    return 0;
}*/



// undirected dfs



/*#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

// Function to perform BFS starting from vertex startVertex
void bfs(unordered_map<char, vector<char>>& graph, char startVertex) {
    unordered_set<char> visited;
    queue<char> q;

    visited.insert(startVertex);
    q.push(startVertex);

    while (!q.empty()) {
        char currentVertex = q.front();
        q.pop();
        cout << currentVertex << " ";

        for (char neighbor : graph[currentVertex]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}

int main() {
    unordered_map<char, vector<char>> graph;

    // Sample input edges
    vector<pair<char, char>> edges = {{'A', 'B'}, {'A', 'C'}, {'B', 'C'}, {'C', 'D'}, {'C', 'E'}, {'A', 'E'}, {'B', 'E'}, {'B', 'D'}};

    // Build the graph
    for (auto& edge : edges) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);  // Assuming the graph is undirected
    }

    // Perform BFS from vertex A
    cout << "BFS traversal from vertex A: ";
    bfs(graph, 'A');
    cout << endl;

    return 0;
}*/


//Kruskal’s algorithm for finding the MST
/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a disjoint set
struct DisjointSet {
    vector<int> parent, rank;
    
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

// Function to compare edges based on their weights
bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

// Function to find the MST using Kruskal's algorithm
vector<Edge> kruskalMST(vector<Edge>& edges, int numVertices) {
    // Sort the edges in non-decreasing order of their weights
    sort(edges.begin(), edges.end(), compareEdges);
    
    vector<Edge> mst;
    DisjointSet ds(numVertices);
    
    for (const Edge& edge : edges) {
        int srcRoot = ds.find(edge.src);
        int destRoot = ds.find(edge.dest);
        
        // If including this edge does not form a cycle, add it to the MST
        if (srcRoot != destRoot) {
            mst.push_back(edge);
            ds.unionSets(srcRoot, destRoot);
        }
    }
    
    return mst;
}

int main() {
    int numVertices = 6;
    vector<Edge> edges = {
        {0, 1, 4},
        {0, 2, 3},
        {1, 2, 1},
        {1, 3, 2},
        {2, 3, 4},
        {3, 4, 2},
        {4, 5, 6}
    };
    
    vector<Edge> mst = kruskalMST(edges, numVertices);
    
    cout << "Minimum Spanning Tree (MST) edges:" << endl;
    for (const Edge& edge : mst) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }
    
    return 0;
}*/



//prim’s algorithm for finding the MST
/*#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure to represent a node in the graph
struct Node {
    int id, weight;
    
    Node(int _id, int _weight) : id(_id), weight(_weight) {}
};

// Structure to represent a comparison function for the priority queue
struct Compare {
    bool operator()(const Node& n1, const Node& n2) {
        return n1.weight > n2.weight;
    }
};

// Function to find the MST using Prim's algorithm
vector<vector<pair<int, int>>> primMST(vector<vector<pair<int, int>>>& graph, int numVertices) {
    vector<vector<pair<int, int>>> mst(numVertices);
    vector<bool> visited(numVertices, false);
    priority_queue<Node, vector<Node>, Compare> pq;
    
    // Start with the first vertex
    pq.push(Node(0, 0));
    
    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();
        
        int currId = curr.id;
        
        // Skip if the vertex is already visited
        if (visited[currId]) {
            continue;
        }
        
        visited[currId] = true;
        
        // Add the edges of the current vertex to the MST
        for (const auto& edge : graph[currId]) {
            int neighborId = edge.first;
            int weight = edge.second;
            
            if (!visited[neighborId]) {
                mst[currId].push_back({neighborId, weight});
                mst[neighborId].push_back({currId, weight});
                pq.push(Node(neighborId, weight));
            }
        }
    }
    
    return mst;
}

int main() {
    int numVertices = 6;
    vector<vector<pair<int, int>>> graph(numVertices);
    
    // Add edges to the graph
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 3});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 2});
    graph[2].push_back({3, 4});
    graph[3].push_back({4, 2});
    graph[4].push_back({5, 6});
    
    vector<vector<pair<int, int>>> mst = primMST(graph, numVertices);
    
    cout << "Minimum Spanning Tree (MST) edges:" << endl;
    for (int i = 0; i < numVertices; i++) {
        for (const auto& edge : mst[i]) {
            cout << i << " - " << edge.first << " : " << edge.second << endl;
        }
    }
    
    return 0;
}*/


/*#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isCyclePresent(vector<vector<int>>& graph, int numVertices) {
    vector<bool> visited(numVertices, false);
    vector<int> parent(numVertices, -1);
    queue<int> q;

    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int neighbor : graph[curr]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                        parent[neighbor] = curr;
                    } else if (parent[curr] != neighbor) {
                        // If the neighbor is already visited and not the parent of the current node,
                        // then there is a cycle in the graph
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    int numVertices = 6;
    vector<vector<int>> graph(numVertices);

    // Add edges to the graph
    graph[0].push_back(1);
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(2);
    graph[3].push_back(4);
    graph[4].push_back(3);
    graph[4].push_back(5);
    graph[5].push_back(4);

    bool hasCycle = isCyclePresent(graph, numVertices);

    if (hasCycle) {
        cout << "Cycle is present in the graph." << endl;
    } else {
        cout << "Cycle is not present in the graph." << endl;
    }

    return 0;
}*/


#include <iostream>
#include <vector>

using namespace std;

bool isCyclePresent(vector<vector<int>>& graph, int numVertices) {
    vector<bool> visited(numVertices, false);
    vector<int> parent(numVertices, -1);

    // Helper function to perform DFS
    bool dfs(int curr) {
        visited[curr] = true;

        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                parent[neighbor] = curr;
                if (dfs(neighbor)) {
                    return true;
                }
            } else if (parent[curr] != neighbor) {
                // If the neighbor is already visited and not the parent of the current node,
                // then there is a cycle in the graph
                return true;
            }
        }

        return false;
    }

    for (int i = 0; i < numVertices; i++) {
        if (!visited[i] && dfs(i)) {
            return true;
        }
    }

    return false;
}

int main() {
    int numVertices = 6;
    vector<vector<int>> graph(numVertices);

    // Add edges to the graph
    graph[0].push_back(1);
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(2);
    graph[3].push_back(4);
    graph[4].push_back(3);
    graph[4].push_back(5);
    graph[5].push_back(4);

    bool hasCycle = isCyclePresent(graph, numVertices);

    if (hasCycle) {
        cout << "Cycle is present in the graph." << endl;
    } else {
        cout << "Cycle is not present in the graph." << endl;
    }

    return 0;
}
