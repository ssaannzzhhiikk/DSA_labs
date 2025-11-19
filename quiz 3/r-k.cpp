/*
hash(s) =  (s[0] * p^(n-1) + s[1] * p^(n-2) + ... + s[n-1] * p^0 ) %mod

 - s[i] is the numeric value of the i-th character ('a' = 1, 'b' = 2, ..., 'z' = 26)
 - p is a small prime number (commonly 31 or 37)
 - mod is a large prime number (like 1e9 + 7) to avoid overflow and reduce hash collisions

Time Complexity: O(n + m), we compute prefix hashes and powers for both text and pattern in O(n + m). Then, we slide a window over the text, and each substring hash is compared in O(1).
Auxiliary Space: O(n + m) ,we store prefix hashes and power arrays for both text and pattern, taking O(n + m) space.
 */


#include <bits/stdc++.h>
using namespace std;

struct RabinKarp{
    const long long MOD = 1e9 + 7;
    const long long BASE = 31;
    vector<long long> hashes, powers;


    RabinKarp(const string &s){
        int n = s.size();
        hashes.assign(n+1, 0);
        powers.assign(n+1, 1);

        for(int i = 0; i < n; i++){
            hashes[i + 1] = (hashes[i] * BASE + (s[i] - 'a' + 1)) % MOD;
            powers[i + 1] = (powers[i] * BASE) % MOD;
        }
    }

    long long getHash(int l, int r){
        long long res = (hashes[r] - hashes[l] * powers[r - l]) % MOD;
        if(res < 0) res += MOD;
        return res;
    }
};

vector<int> searchPattern(const string &text, const string &pattern){
    int n = text.size(), m = pattern.size();
    vector<int> pos;
    if(m > n) return pos;
    
    RabinKarp ht(text), hp(pattern);
    long long target = hp.getHash(0, m);

    for(int i = 0; i + m <= n; i++){
        if(ht.getHash(i, i + m) == target){
            pos.push_back(i);
        }
    }

    return pos;
}
