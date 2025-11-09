#include <bits/stdc++.h>
using namespace std;

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
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> KMP(const string &t, const string &p) {
    vector<int> lps = computeLPS(p);
    vector<int> res;

    int i = 0, j = 0;
    int n = t.size(), m = p.size();

    while (i < n) {
        if (t[i] == p[j]) {
            i++; j++;
        }

        if (j == m) {
            res.push_back(i - m);
            j = lps[j - 1];
        }
        else if (i < n && t[i] != p[j]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }

    return res;
}
