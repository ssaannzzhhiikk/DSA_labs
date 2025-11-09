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

int KMP(const string &t, const string &p){
    vector<int> lps = computeLPS(p);
    int n = t.size(), m = p.size();
    for(int i = 0, j = 0; i < n; i++){
        while(j > 0 && t[i] != p[j]) j = lps[j - 1];
        if(t[i] == p[j]) j++;
        if(j == m) return i - m + 1;
    }
    return -1;
}

#define dalshe ios::sync_with_stdio(false);
#define menshe cin.tie(nullptr);

int main(){
    dalshe menshe;

    string A, B;
    cin >> A >> B;

    int n = A.size();
    string AA = A + A;

    int pos = KMP(AA, B);
    if(pos == -1){
        cout << -1;
        return 0;
    }

    int shift = (n - pos % n) % n;
    cout << shift;
    return 0;
}