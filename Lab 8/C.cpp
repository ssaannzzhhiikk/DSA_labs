#include <bits/stdc++.h>
using namespace std;

struct RabinKarp{
    const long long MOD = 1e9 + 7;
    const long long BASE = 31;
    vector<long long> h, p;

    RabinKarp(const string &s){
        int n = s.size();
        h.assign(n+1, 0);
        p.assign(n + 1, 1);
        for(int i = 0; i < n; i++){
            h[i + 1] = (h[i] * BASE + (s[i] - 'a' + 1)) % MOD;
            p[i + 1] = (p[i] * BASE) % MOD;
        }
    }

    long long get(int l, int r){
        long long res = (h[r] - h[l] * p[r - l]) % MOD;
        if(res < 0) res += MOD;
        return res;
    }
};

vector<int> searchPattern(const string &text, const string &pattern){
    int n = text.size(), m = pattern.size();
    RabinKarp ht(text), hp(pattern);
    long long target = hp.get(0, m);
    vector<int> pos;
    for(int i = 0; i + m <= n; i++){
        if(ht.get(i, i + m) == target)
        pos.push_back(i);
    }
    return pos;
}


int main(){
    string big;
    int n;
    cin >> big >> n;
    vector<string> small(n);
    for(int i = 0; i < n; i++) cin >> small[i];

    int m = big.size();
    vector<bool> covered(m, false);

    for( auto &pat : small){
        vector<int> mathches = searchPattern(big, pat);
        for(int pos : mathches){
            for(int i = pos; i < pos + pat.size(); i++){
                covered[i] = true;
            }
        }
    }

    cout << (all_of(covered.begin(), covered.end(), [](bool c){ return c; }) ? "YES" : "NO");   
}