/*
Depth-First Search explores a graph deeply, going as far as possible along
each branch before backtracking.
Time Complexity: O(V + E)

u → the current node you are processing
v → a neighbor of u
*/

#include <bits/stdc++.h>
using namespace std;

void dfsRec(int u, const vector<vector<int>>& adj, vector<bool>& visited) {
    if (visited[u]) return;      // base case

    visited[u] = true;           // mark current node
    cout << u << " ";            // visit = process

    for (int v : adj[u]) {       // iterate over neighbors
        if (!visited[v]) {
            dfsRec(v, adj, visited);  // go deep
        }
    }
}



void dfs(int start, vector<vector<int>> & adj){
    int n = adj.size();
    vector<bool> visited(n, false);
    dfsRec(start, adj, visited);
}

/*
      0
     / \
    1   2
    |  / \
    3 4   5

 0 → 1 → 3 → backtrack → 2 → 4 → backtrack → 5

Final order: 0 1 3 2 4 5

*/