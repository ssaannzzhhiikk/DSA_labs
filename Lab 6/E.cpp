#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(int j = 0; j < n; j++){
        vector<int> col;
        for(int i = 0; i < m; i++) col.push_back(a[i][j]);
        sort(col.rbegin(), col.rend());
        for(int i = 0; i < m; i++) a[i][j] = col[i];
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
