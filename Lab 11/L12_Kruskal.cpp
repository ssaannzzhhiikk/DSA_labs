#include <bits/stdc++.h>
using namespace std;

class DisjointSetUnion{
private:
    vector<int> parent, rank;
public:
    DisjointSetUnion(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int v){
        if(v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if(rank[a] == rank[b]) rank[a]++;
        }
    }
};

struct Edge {
    int u, v, w;
};

bool compare(const Edge &a, const Edge &b){
    return a.w < b.w;
}

int kruskal(int n, vector<Edge> &edges){
    sort(edges.begin(), edges.end(), compare);
    DisjointSetUnion DSU(n);

    int mst_weight = 0;
    vector<Edge> mst_edges;

    for(Edge &e : edges){
        if(DSU.find(e.u) != DSU.find(e.v)){
            DSU.unite(e.u, e.v);
            mst_weight += e.w;
            mst_edges.push_back(e);
        }
    }

    cout << "Edges in MST:\n";
    for(auto &e : mst_edges)
        cout << e.u << "--" << e.v << " (weight=" << e.w << ")\n";

    return mst_weight;
}


