#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;


vector<int> dijkstra(vector<vector<pii>> &adj, int start){
    int V = adj.size();
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(V, INT32_MAX); // массив расстояний

    dist[start] = 0; pq.emplace(0, start);

    while(!pq.empty()){
        pii top = pq.top();
        pq.pop();

        int d = top.first;  // current distance
        int u = top.second; // current vertex

        if(d > dist[u]) continue;

        for(pii &p : adj[u]){
            int v = p.first, w = p.second;  // sosed i weight

            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist;
}

/*
0 - kuda to infinity
1 Select minimum unseen neighbor vertex


0: (1,4), (2,1)
1: (3,1)
2: (1,2), (3,5)
3: ()

*/