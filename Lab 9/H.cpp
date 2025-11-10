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



int main() {
    dalshe menshe;
    string s;
    cin >> s;
    int n = s.size();
    vector<int> lps = computeLPS(s);
    int ans = 0;

    if(n < 3){
        cout << 0;
        return 0;
    }


    for (int i = 1; 2 * i < n; ++i) {
        // Рассматриваем префикс s[0...2*i - 1]
        int k = 2 * i - 1; // Индекс lps, который нас интересует
        int L = 2 * i;     // Длина этого префикса
        
        // lps_val - длина наибольшего префикса-суффикса (L')
        int lps_val = lps[k];
        
        // T - длина наименьшего периода
        // T = L - L'
        int T = L - lps_val;
        
        // Наше условие (a=b) эквивалентно тому, что префикс
        // s[0...k] имеет период i.
        // Это верно, если i кратно наименьшему периоду T.
        // (Также нужно, чтобы T "покрывало" всю строку L,
        // но если i % T == 0, то L % T == 0 автоматически).
        if (i % T == 0) {
            ans++;
        }
    }
    cout << ans;
}

/*

a + b + c = S  and a + c = b + c
ab + ab + ababcx
abab + abab + cx

i: 0 1 2 3 4 5 6 7 8 9
-< a b a b a b a b c x
-> 0 0 1 2 3 4 5 6 0 0


*/