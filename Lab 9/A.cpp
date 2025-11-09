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

bool KMP(const string &t, const string &p) {
    vector<int> lps = computeLPS(p);
    vector<int> res;

    int i = 0, j = 0;
    int n = t.size(), m = p.size();

    while (i < n) {
        if (t[i] == p[j]) {
            i++; j++;
        }

        if (j == m) {
            return true;
        }
        else if (i < n && t[i] != p[j]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }

    return false;
}

#define dalshe ios::sync_with_stdio(false);
#define menshe cin.tie(nullptr);



int main(){
    dalshe menshe;

    string A, B;
    cin >> A >> B;

    int n = A.size();
    int m = B.size();

    int k = (m + n - 1) / n; //ceil(m/n)

    string s;
    s.reserve((k+2) * n);

    for(int i = 0; i < k; i++) s+= A;
      if (KMP(s, B)) {
        cout << k;
        return 0;
    }

    s+=A;
    if(KMP(s, B)){
        cout << k + 1;
        return 0;
    }

    cout << -1;
    return 0;

}