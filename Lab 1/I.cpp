#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    queue<int> S, K;

    for(int i = 0; i < n; i++){
        if(s[i] == 'K'){
            K.push(i);
        } else {
            S.push(i);
        }
    }

    while((!K.empty() && !S.empty())){

        if (K.front() < S.front()) {
            int survivor = K.front();
            K.pop();
            S.pop();
            K.push(survivor + n);
        } else {
            int survivor = S.front();
            S.pop();
            K.pop();
            S.push(survivor + n);
        }

    }

    if(S.empty()){
        cout << "KATSURAGI";
    } else{
        cout << "SAKAYANAGI";
    }

}