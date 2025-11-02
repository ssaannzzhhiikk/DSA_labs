#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const long long BASE = 31;

// Compute prefix hashes for a string
vector<long long> computeHash(const string &s) {
    int n = s.size();
    vector<long long> h(n + 1, 0), p(n + 1, 1);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] * BASE + (s[i] - 'a' + 1)) % MOD;
        p[i + 1] = (p[i] * BASE) % MOD;
    }
    return h;
}

long long getHash(const vector<long long> &h, const vector<long long> &p, int l, int r) {
    long long res = (h[r] - h[l] * p[r - l]) % MOD;
    if (res < 0) res += MOD;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    vector<string> s(k);
    for (int i = 0; i < k; i++) cin >> s[i];

    string base = s[0];
    int n = base.size();

    vector<long long> hBase = computeHash(base);
    vector<long long> p(n + 1, 1);
    for (int i = 1; i <= n; i++) p[i] = (p[i - 1] * BASE) % MOD;

    string ans = "";

    // store all substrings of base string
    for (int len = n; len >= 1; len--) { // start from longest
        unordered_map<long long, string> hashToSub;
        for (int i = 0; i + len <= n; i++) {
            long long h = getHash(hBase, p, i, i + len);
            hashToSub[h] = base.substr(i, len);
        }

        // check each substring hash if appears in all strings
        for (auto &[hashVal, sub] : hashToSub) {
            bool ok = true;
            for (int j = 1; j < k && ok; j++) {
                if (s[j].find(sub) == string::npos)
                    ok = false;
            }
            if (ok) {
                cout << sub << "\n";
                return 0; // longest found
            }
        }
    }
}
