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

        if( K.front() < S.front()){
            S.pop();
            K.push(K.front() + n);
            K.pop();
        } else{
            K.pop();
            S.push(S.front() + n);
            S.pop();
        }
    }

    if(S.empty()){
        cout << "KATSURAGI";
    } else{
        cout << "SAKAYANAGI";
    }

}