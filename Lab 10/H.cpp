#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
char c[101][101];
bool used[101][101];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> c[i][j];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(c[i][j] == '1' && !used[i][j]){
                ans++;
                queue<pair<int,int>> q;
                used[i][j] = true;  // помечаем стартовую клетку
                q.push({i,j});

                while(!q.empty()){
                    auto [l,r] = q.front();
                    q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = l + dx[dir];
                        int ny = r + dy[dir];
                        if(nx >= 1 && nx <= n && ny >= 1 && ny <= m &&
                           c[nx][ny] == '1' && !used[nx][ny]){
                            used[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }

    cout << ans << "\n";
}
