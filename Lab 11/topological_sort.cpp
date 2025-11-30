/*
Topological sort is a linear ordering of nodes in a Directed Acyclic Graph (DAG).
Every edge u → v means u must appear before v in the ordering.
Used for task scheduling, course prerequisites, build systems, etc.


Topological sort is DFS traversal + stack.
You explore each node’s dependencies first, push nodes after all neighbors are visited, and then reverse the stack to get a valid order.
It’s basically DFS “with memory” to respect dependency order — nothing more, nothing less.
*/

#include <bits/stdc++.h>
using namespace std;

void dfsTopo(int u, const vector<vector<int>> &adj, vector<bool>& visited, stack<int>& st){
    visited[u] = true;

    for(int v : adj[u]){
        if(!visited[v]){
            dfsTopo(v, adj, visited, st);
        }
    }
    st.push(u);
}

vector<int> topologicalSort(const vector<vector<int>>& adj){
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> st;

    for(int u = 0; u < n; ++u){
        if(!visited[u]){
            dfsTopo(u, adj, visited, st);
        }
    }

    vector<int> topoOrder;
    while(!st.empty()){
        topoOrder.push_back(st.top());
        st.pop();
    }

    return topoOrder;

}

int main() {
    vector<vector<int>> adj = {
        {1, 2}, // 0 → 1, 2
        {3},    // 1 → 3
        {3},    // 2 → 3
        {}      // 3 → none
    };

    vector<int> order = topologicalSort(adj);

    cout << "Topological order: ";
    for (int u : order)
        cout << u << " ";
    cout << endl;

    return 0;
}