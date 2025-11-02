#include <bits/stdc++.h>
using namespace std;

const long long MOD1 = 1000000007;
const long long MOD2 = 1000000009;
const long long BASE1 = 31;
const long long BASE2 = 37;

struct DoubleHash {
    vector<long long> h1, h2, p1, p2;
    int n;

    DoubleHash(const string &s) {
        n = s.size();
        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        p1.assign(n + 1, 1);
        p2.assign(n + 1, 1);

        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * BASE1 + (s[i] - 'a' + 1)) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + (s[i] - 'a' + 1)) % MOD2;
            p1[i + 1] = (p1[i] * BASE1) % MOD1;
            p2[i + 1] = (p2[i] * BASE2) % MOD2;
        }
    }

    pair<long long, long long> get(int l, int r) const {
        long long x1 = (h1[r] - h1[l] * p1[r - l]) % MOD1;
        long long x2 = (h2[r] - h2[l] * p2[r - l]) % MOD2;
        if (x1 < 0) x1 += MOD1;
        if (x2 < 0) x2 += MOD2;
        return {x1, x2};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int q;
    cin >> s >> q;

    int n = s.size();
    DoubleHash dh(s);
    unordered_map<uint64_t, int> freq;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            auto [x1, x2] = dh.get(i, j);
            uint64_t key = ((uint64_t)x1 << 32) ^ (uint64_t)x2;
            freq[key]++;
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        auto [x1, x2] = dh.get(l, r);
        uint64_t key = ((uint64_t)x1 << 32) ^ (uint64_t)x2;
        cout << freq[key] << '\n';
    }

    return 0;
}
