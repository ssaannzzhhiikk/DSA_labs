#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;

int prim(int n, vector<pair<int, PII>>& edges) {
    // строим граф сразу в виде списка смежности
    vector<vector<PII>> adj(n);
    for(auto &[w, p] : edges) {
        int u = p.first, v = p.second;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<bool> inMST(n, false);
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, 0}); // начинаем с вершины 0

    int mst_weight = 0;
    vector<PII> mst_edges;

    while(!pq.empty()) {
        auto [w, v] = pq.top(); pq.pop();
        if(inMST[v]) continue;
        inMST[v] = true;
        mst_weight += w;

        if(w != 0) mst_edges.push_back({v, w}); // просто для вывода

        for(auto &[to, weight] : adj[v])
            if(!inMST[to])
                pq.push({weight, to});
    }

    cout << "Edges Selected (vertex, weight):\n";
    for(auto &[v, w] : mst_edges)
        cout << v << " - " << w << "\n";

    return mst_weight;
}

int main() {
    int n = 5;
    vector<pair<int, PII>> edges = {
        {2, {0,1}}, {6, {0,3}}, {3, {1,2}}, {8, {1,3}},
        {5, {1,4}}, {7, {2,4}}, {9, {3,4}}
    };

    int mst_w = prim(n, edges);
    cout << "Total weight of MST: " << mst_w << "\n";

    return 0;
}
