DFS is a fundamnetal traverse used for:
 - Visiting all nodes
 - Detecting cycles
 - Checking connectivity
 - Preparing for other algorithms like Topo sort

1.1 DFS Traversal (Recursion Template)
```
void dfs(int v){
    visited[v] = true;
    for(int to : g[v]){
        if(!visited[to]) dfs(to);
    }
}
```

1.2 DFS Cycle Detection
Directed Graph — Cycle Detection

We use 3-coloring (state array):
 - 0 = unvisited
 - 1 = in recursion stack
 - 2 = finished
A cycle exists if we ever see an edge to a 1.
```cpp
bool dfs(int v){
    color[v] = 1;
    for(int to : g[v]){
        if(color[to] == 1) return true;        // cycle
        if(color[to] == 0 && dfs(to)) return true;
    }
    color[v] = 2;
    return false;
}
```

Undirected Graph — Cycle Detection

A cycle exists if we meet a visited vertex that is not parent:
```cpp
bool dfs(int v, int p){
    visited[v] = true;
    for(int to : g[v]){
        if(to == p) continue;
        if(visited[to]) return true;
        if(dfs(to, v)) return true;
    }
    return false;
}
```