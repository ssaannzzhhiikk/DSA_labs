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


int main() {
    dalshe menshe;
    string s;
    cin >> s;
    vector<int> lps = computeLPS(s);

    cout << s.size() - lps.back();
}

/*
zzz 
0 1 2

bcabcab
0 0 0 1 2 3 4 
*/