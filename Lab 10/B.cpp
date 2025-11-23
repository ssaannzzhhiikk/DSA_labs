#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    
    // Считываем матрицу смежности
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> adj[i][j];
    
    int start, end;
    cin >> start >> end;
    start--; end--;
    vector<int> dist(n, -1);
    queue<int> q;
    
    dist[start] = 0;
    q.push(start);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < n; i++) {
            if(adj[cur][i] == 1 && dist[i] == -1) {
                dist[i] = dist[cur] + 1;
                q.push(i);
            }
        }
    }
    
    cout << dist[end] << endl;
    return 0;
}
