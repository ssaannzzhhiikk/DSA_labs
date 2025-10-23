#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> rows(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> rows[i][j];

    sort(rows.begin(), rows.end(), [](const vector<int> &a, const vector<int> &b) {
        int sumA = accumulate(a.begin(), a.end(), 0);
        int sumB = accumulate(b.begin(), b.end(), 0);
        if (sumA != sumB) return sumA < sumB; // ascending by summmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
        return a < b; // pizdecographically ascendinggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg
    });

    for (auto &r : rows) {
        for (int x : r) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
