#include <bits/stdc++.h>
using namespace std;


class DisjointSetUnion{
private:
    vector<int> rank, parent;
public:
    DisjointSetUnion(int n){
        rank.resize(n);
        parent.resize(n);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int v){
        if(parent[v] == v){
            return v;
        } 
        return parent[v] = find(parent[v]);
    }

    void union_set(int v, int u){
        u = find(u);
        v = find(v);

        if(rank[v] > rank[u]){
            parent[u] = v;
        } else if(rank[v] < rank[u]){
            parent[v] = u;
        } else{
            parent[u] = v;
            rank[v]++;
        }
    }
};


int kruskal(int n, vector<pair<int, pair<int, int>>> edges){
    DisjointSetUnion DSU(n);
    int mst_weight = 0;
    vector<pair<int, pair<int, int>>> mst_edges;

    sort(edges.begin(), edges.end());

    for(int i = 0; i < edges.size(); i++){
        int x = edges[i].second.first;
        int y = edges[i].second.second;

        if(DSU.find(x) != DSU.find(y)){
            DSU.union_set(x, y);
            cout << x+1 << " and " << y+1 << endl;
            mst_weight += edges[i].first;
        }
    }

    return mst_weight;
}


int main(){
    int n, m, x, y, l;
    cin >> n >> m;
    vector<pair<int , pair<int, int>>> edges;
    for(int i = 0; i < m; i++){
        cin >> x >> y >> l;
        x--; y--;
        edges.push_back(make_pair(l, make_pair(x, y)));
    }

    int weight_mst = kruskal(n, edges);
    cout << "Minimum weight: " <<weight_mst;
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