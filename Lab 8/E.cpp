#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    string s = "";
    for(int i = 0; i < n; i++){
        long long diff;
        if(i == 0) diff = p[i];
        else diff = p[i] - p[i - 1];

        long long val = diff / (1LL << i);
        s += char(val + 97);  
    }

    cout << s;
}