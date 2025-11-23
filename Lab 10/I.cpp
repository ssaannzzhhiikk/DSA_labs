#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<int> in_degree(n+1, 0);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_degree[v]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(in_degree[i] == 0) q.push(i);
    }

    vector<int> order;

    while(!q.empty()){
        int v = q.front(); q.pop();
        order.push_back(v);
        for(int to : adj[v]){
            in_degree[to]--;
            if(in_degree[to] == 0) q.push(to);
        }
    }

    if((int)order.size() == n){
        cout << "Possible\n";
        for(int x : order) cout << x << " ";
        cout << "\n";
    } else {
        cout << "Impossible\n";
    }

    return 0;
}
