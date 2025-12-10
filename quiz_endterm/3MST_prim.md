Prim’s Algorithm (like Dijkstra for MST)

Push edges into a priority queue, always take smallest available edge.

```cpp
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
pq.push({0, start});
while(!pq.empty()){
    auto [w, v] = pq.top(); pq.pop();
    if(visited[v]) continue;
    visited[v] = true;
    mst += w;
    for(auto [to, cost] : g[v])
        if(!visited[to]) pq.push({cost, to});
}
```