#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> arr1(n);
    for (int i = 0; i < n; i++) cin >> arr1[i];

    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < m; i++) cin >> arr2[i];

    vector<int> merged(n + m);
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) merged[k++] = arr1[i++];
        else merged[k++] = arr2[j++];
    }

    while (i < n) merged[k++] = arr1[i++];
    while (j < m) merged[k++] = arr2[j++];

    for (int x : merged)
        cout << x << " ";
}
