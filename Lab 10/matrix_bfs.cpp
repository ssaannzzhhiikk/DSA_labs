// C++ program to perform BFS using adjacency matrix
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS traversal from a given source
vector<int> bfsTraversal(int v, 
            vector<vector<int>> &edges, int src) {

    // Initialize the adjacency matrix
    vector<vector<int>> adj(v, vector<int>(v, 0));

    // Fill the matrix using edge list
    for (auto &edge : edges) {
        int a = edge[0];
        int b = edge[1];
        adj[a][b] = 1;
        adj[b][a] = 1;  
    }

    // Prepare for BFS
    vector<bool> visited(v, false);
    vector<int> res;
    queue<int> q;

    // Start BFS from the source vertex
    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        // Visit all unvisited neighbors
        for (int i = 0; i < v; i++) {
            if (adj[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    return res;
}

// Driver code
int main() {
    int v = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}};
    int src = 0;

    vector<int> traversal = bfsTraversal(v, edges, src);
    
    for (int x : traversal) {
        cout << x << " ";
    }

    return 0;
}