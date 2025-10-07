#include <bits/stdc++.h>
using namespace std;



int main(){
    priority_queue<int> pq;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        pq.push(x);
    }

    while(pq.size() > 1){
        int bir = pq.top();
        pq.pop();

        int eki = pq.top();
        pq.pop();

        if(bir > eki){
            pq.push(bir-eki);
        }
    }

    if(pq.size() == 0) cout << 0;
    else cout << pq.top();
}