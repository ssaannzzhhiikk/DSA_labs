#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n+1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dist(n+1, -1);
    queue<int> bfsq;
    
    auto addRed = [&](int v){
        if(dist[v]==0) return; // уже красная
        dist[v] = 0;
        bfsq.push(v);
        while(!bfsq.empty()){
            int cur = bfsq.front(); bfsq.pop();
            for(int to : g[cur]){
                if(dist[to]==-1 || dist[to] > dist[cur]+1){
                    dist[to] = dist[cur]+1;
                    bfsq.push(to);
                }
            }
        }
    };

    for(int i = 0; i < q; i++){
        int t, v;
        cin >> t >> v;
        if(t==1){
            addRed(v);
        } else {
            cout << dist[v] << "\n";
        }
    }

    return 0;
}
