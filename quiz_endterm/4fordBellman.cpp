#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<int> bellmanFord(int src, vector<vector<int>> & edges, int V){
    vector<int> dist(V, INF);
    dist[src] = 0;

    for(int i = 0; i < V; i++){
        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(dist[u] != INF && dist[u] + w < dist[v]){
                if(i == V - 1) return {-1};
                dist[v] = dist[u] + w;
            }
        }
    }

}