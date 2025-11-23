#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> parent(n+1, -1);
    vector<int> children(n+1, 0);
    vector<bool> used(n+1, false);
    int BigFam = 0;

    for(int i=1;i<=n;i++){
        if(!used[i]){
            // корень компоненты — минимальная вершина
            int root = i;
            queue<int> q;
            q.push(root);
            used[root] = true;

            while(!q.empty()){
                int v = q.front(); q.pop();
                for(int to : g[v]){
                    if(!used[to]){
                        used[to] = true;
                        parent[to] = v;
                        children[v]++; // v получает прямого ребёнка
                        q.push(to);
                    }
                }
            }

            // считаем BigFam для этой компоненты
            queue<int> q2;
            q2.push(root);
            while(!q2.empty()){
                int v = q2.front(); q2.pop();
                if(parent[v] == -1 || children[v] > children[parent[v]])
                    BigFam++;
                for(int to : g[v]){
                    if(parent[to]==v)
                        q2.push(to);
                }
            }
        }
    }

    cout << BigFam << "\n";
}
