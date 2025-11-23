#include <bits/stdc++.h>
using namespace std;

int marioWar(int m, int n, vector<vector<int>>& grid) {
    queue<tuple<int,int,int>> q; // x, y, time
    int mushrooms = 0;

    // Инициализация очереди всеми Марио и подсчет грибов
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 2) {
                q.push({i, j, 0});
            } else if(grid[i][j] == 1) {
                mushrooms++;
            }
        }
    }

    if(mushrooms == 0) return 0;

    int max_time = 0;
    int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    while(!q.empty()) {
        auto [x, y, time] = q.front();
        q.pop();
        for(auto &d : dirs) {
            int nx = x + d[0];
            int ny = y + d[1];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                grid[nx][ny] = 2;
                mushrooms--;
                q.push({nx, ny, time+1});
                max_time = max(max_time, time+1);
            }
        }
    }

    return mushrooms == 0 ? max_time : -1;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    cout << marioWar(m, n, grid) << endl;

    return 0;
}
