3.1 Kruskal’s Algorithm (Greedy, DSU)

Sort edges by weight, add if it does not form a cycle.

DSU:
```cpp
int find(int v){
    if(parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b) parent[b] = a;
}
```

Kruskal:
```cpp
sort(edges.begin(), edges.end());
for(auto &e : edges){
    if(find(e.u) != find(e.v)){
        unite(e.u, e.v);
        mst += e.w;
    }
}
```