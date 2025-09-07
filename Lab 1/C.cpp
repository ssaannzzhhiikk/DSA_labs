#include <bits/stdc++.h>
using namespace std;
int main(){
    string s, s1, s2;
    stack<char>st1, st2;
    getline(cin, s);
    int length = s.length();
    int i = 0;

    while(i < length){
        if(s[i] == ' '){
            s1 = s.substr(0, i);
            s2 = s.substr(i+1);
            break;
        }
        i++;
    }
    

    for(int i = 0; i < s1.length(); i++){
        if(s1[i] == '#' && !st1.empty()){
            st1.pop();
        } else{
            st1.push(s1[i]);
        }
    }

    for(int i = 0; i < s2.length(); i++){
        if(s2[i] == '#' && !st2.empty()){
            st2.pop();
        } else{
            st2.push(s2[i]);
        }
    }

    string a = "", b = "";
    while(!st1.empty()){
        a+= st1.top();
        st1.pop();
    }


    while(!st2.empty()){
        b+= st2.top();
        st2.pop();
    }

    if(a == b){
        cout << "Yes"; 
    } else{
        cout << "No";
    }
}