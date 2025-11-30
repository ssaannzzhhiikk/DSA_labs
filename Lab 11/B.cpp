/*
1 2 3 4 5

1 _ 2 _ 3 _ 4 _ 5
2   5   4   2   8

1 - 2  7
1 - 3  6
1 - 4  4

7 + 6 + 10 + 4

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> d(n);
    long long sum = 0;
    long long mn = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        cin >> d[i];
        sum += d[i];
        mn = min(mn, d[i]);
    }

    cout << sum + (n - 2) * mn;
    return 0;
}