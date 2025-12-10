Topological Sort

Works only for DAG (Directed Acyclic Graph).

2.1 DFS-based Topo Sort

Push vertices to list after exploring children.
```cpp
void dfs(int v){
    visited[v] = true;
    for(int to : g[v])
        if(!visited[to]) dfs(to);
    order.push_back(v);
}
```

Reverse order at the end.