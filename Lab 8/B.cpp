#include <bits/stdc++.h>
using namespace std;


class RabinKarpHash {
private:
    const int mod = 1e9 + 7;
    const int base = 31;
    vector<int> hash;
    vector<int> power;

    // modualr addition
    int add(int a, int b){
        a+=b;
        if(a >= mod) a -= mod;
        return a;
    }

    // modular substraction
    int sub(int a, int b) {
        a -= b;
        if (a < 0) a += mod;
        return a;
    }

    // modular multiplication
    int mul(int a, int b){
        return (int)((1LL * a * b) % mod);
    }

    // caharacter to integer
    // ('a' = 1, ..., 'z' = 26)
    int charToInt(char c){
        if (c >= 'a' && c <= 'z') return c - 'a' + 1;
        if (c >= 'A' && c <= 'Z') return c - 'A' + 27; // optional
        return 0;
    }


public:
    RabinKarpHash(string &s) {
        int n = s.size();
        if (n == 0) return;
        hash.resize(n);
        power.resize(n);

        hash[0] = charToInt(s[0]);
        power[0] = 1;

        for(int i = 1; i < n; i++){
            hash[i] = add(mul(hash[i - 1], base), charToInt(s[i]));

            power[i] = mul(power[i - 1], base);
        }
    }

    int getSubHash(int l, int r) {
        int h = hash[r];
        if(l > 0) {
            h = sub(h, mul(hash[l - 1], power[r - l + 1])); 
        }
        return h;
    }
};


vector<int> searchPattern(string &text, string &pattern){
    int n = text.size(), m = pattern.size();

    RabinKarpHash textHash(text);
    RabinKarpHash patHash(pattern);

    int patternHash = patHash.getSubHash(0, m - 1);
    vector<int> result;

    for(int i = 0; i <= n - m; i++){
        int subHash = textHash.getSubHash(i, i + m - 1);

        if (subHash == patternHash) {
            result.push_back(i);
        }
    }

    return result;
}



int main(){
    string s1;
    string s2;
    string p;

    cin >> s1;
    cin >> s2;
    cin >> p;

    vector<int> pos1 = searchPattern(s1, p);
    vector<int> pos2 = searchPattern(s2, p);

    map<int, int> same;

    for(int i = 0; i < pos1.size(); i++){
        same[pos1[i]]++;
    }

    for(int i = 0; i < pos2.size(); i++){
        same[pos2[i]]++;
    }

    int count = 0;
    for(auto &x : same){
        if(x.second > 1){
            count++;
        }
    }

    cout << count;
}