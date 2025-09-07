#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    stack<char> st;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(st.empty() || st.top() != s.at(i)){
            st.push(s.at(i));
        } else if(st.top() == s.at(i)){
            st.pop();
        }
    }

    if(st.empty()){
        cout << "YES";
    } else{
        cout << "NO";
    }
}