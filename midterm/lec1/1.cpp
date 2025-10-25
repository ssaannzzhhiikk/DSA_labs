// Royal Flush from lab 1

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        deque<int> d;

        for(int i = n; i > 0; i--){
            d.push_front(i);

            for(int j = 0; j < i; j++){
                d.push_front(d.back());
                d.pop_back();
            }
        }

        while(!d.empty()){
            cout << d.front() << " ";
            d.pop_front();
        }
        cout << '\n';
    }

}