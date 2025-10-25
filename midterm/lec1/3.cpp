#include <bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    stack<char> st1, st2;

    for(int i = 0; i < s1.size(); i++){
        if(s1[i] == '#'){
            if (!st1.empty()) st1.pop();
        } else{
            st1.push(s1[i]);
        }
    }

    for(int i = 0; i < s2.size(); i++){
        if(s2[i] == '#'){
            if (!st2.empty()) st2.pop();
        } else{
            st2.push(s2[i]);
        }
    }

    if( st1 == st2){
        cout << "Yes";
    } else{
        cout << "No";
    }
}