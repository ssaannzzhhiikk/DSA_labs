#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for(auto &s : a) cin >> s;

    sort(a.begin(), a.end(), [](const string &x, const string &y){
        
        if(x.substr(6) != y.substr(6)) 
            return x.substr(6) < y.substr(6);

        if(x.substr(3,2) != y.substr(3,2)) 
            return x.substr(3,2) < y.substr(3,2);

        return x.substr(0,2) < y.substr(0,2);
    });

    for(auto &s : a) cout << s << '\n';
}
