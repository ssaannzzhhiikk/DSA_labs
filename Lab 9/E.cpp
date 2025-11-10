#include <bits/stdc++.h>
using namespace std;

#define dalshe ios::sync_with_stdio(false);
#define menshe cin.tie(nullptr);

vector<int> computeLPS(const string &p) {
    int m = p.size();
    vector<int> lps(m, 0);
    int len = 0;

    for (int i = 1; i < m; ) {
        if (p[i] == p[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) len = lps[len - 1];
            else { lps[i] = 0; i++; }
        }
    }
    return lps;
}

int main() {
    dalshe menshe;
    int n, m;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s >> m;
        vector<int> lps = computeLPS(s);
        int len_to_add = s.size() - lps.back();
        int total_len = s.size() + (m - 1) * len_to_add;
        cout << total_len << endl;
    }
}
