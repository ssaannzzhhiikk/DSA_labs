#include <bits/stdc++.h>
using namespace std;

#define dalshe ios::sync_with_stdio(false);
#define menshe cin.tie(nullptr);

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


int main() {
    dalshe menshe;
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    // Чтение рёбер
    for(int i = 0; i < m; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--; // делаем 0-индексацию
        edges[i].v--;
    }

    // Запуск Краскала
    int mst_weight = kruskal(n, edges);

    cout << "Total MST weight = " << mst_weight << "\n";

    return 0;
}

/*
6 9
1 2 4
1 3 4
2 3 2
2 4 5
3 4 5
3 5 6
4 5 3
4 6 6
5 6 2
*/