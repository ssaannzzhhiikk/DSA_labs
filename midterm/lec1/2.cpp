// Nugman and stk from lab1

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    stack<int> ages;
    cin >> n;

    vector<int> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i]; 

    for(int i = 0; i < n; i++){
        while(!ages.empty() && ages.top() > vec[i]) ages.pop();
        
        if(ages.empty()) cout << -1 << " ";

        else cout << ages.top() << " ";

        ages.push(vec[i]);
    }
}