#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    long long sum = 0;
    int left = 0;
    int ans = INT_MAX;

    for(int right = 0; right < n; right++) {
        sum += a[right];

        while(sum >= k) {
            ans = min(ans, right - left + 1);
            sum -= a[left];
            left++;
        }
    }

    cout << ans << "\n";
    return 0;
}
