#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> vec;
    stack<int> st;

    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        vec.push_back(n);
    }

    for(int i = 0; i < N; i++){
        while(!(st.empty()) && (st.top() > vec.at(i)) ){
            st.pop();
        }
        if( st.empty()){
            cout << -1 << " ";
        } else{
            cout << st.top() << " ";
        }

        st.push(vec.at(i));
    }

 
        
}