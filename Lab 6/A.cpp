#include <bits/stdc++.h>
using namespace std;

bool vowel(char c){
    return (c == 'a' || c == 'o' || c == 'i' || c == 'e' || c == 'u');
}


int main(){
    int n;
    string s, vw = "", nv = "";
    
    cin >> n;
    cin >> s;
    sort(s.begin(), s.end());

    for(int i = 0; i < n; i++){
        if(vowel(s[i])){
            vw += s[i];
        } else{
            nv += s[i];
        }
    }

    cout << vw + nv;
    // there are lot of easier solutions =)
}