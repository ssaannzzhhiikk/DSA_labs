#include <bits/stdc++.h>
using namespace std;

bool canFinish(vector<long long>& bags, long long K, long long H) {
    long long hours = 0;
    for (long long gold : bags) {
        hours += (gold + K - 1) / K;
        if (hours > H) return false;
    }
    return hours <= H;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long H;
    cin >> N >> H;

    vector<long long> bags(N);
    long long maxGold = 0;
    for (int i = 0; i < N; i++) {
        cin >> bags[i];
        maxGold = max(maxGold, bags[i]);
    }

    long long left = 1, right = maxGold, ans = maxGold;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (canFinish(bags, mid, H)) {
            ans = mid;        
            right = mid - 1;
        } else {
            left = mid + 1;    
        }
    }

    cout << ans << "\n";
    return 0;
}
