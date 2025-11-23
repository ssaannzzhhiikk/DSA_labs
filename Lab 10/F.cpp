#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n+1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int s, f;
    cin >> s >> f;

    vector<bool> visited(n+1, false);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int to : g[cur]) {
            if(!visited[to]) {
                visited[to] = true;
                q.push(to);
            }
        }
    }

    if(visited[f])
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
