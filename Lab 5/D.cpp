#include <bits/stdc++.h>
using namespace std;

int main() {
    
    priority_queue<long long,vector<long long>,greater<long long>>pq;
    
    long long n, m, x;
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        cin >> x;
        pq.push(x);
    }

    int count = 0;
    while(pq.top() < m && pq.size() > 1){
        int bir = pq.top();
        pq.pop();
        int eki = pq.top();
        pq.pop();

        int d = bir + 2 * eki;
        pq.push(d);
        
        count++;
    }

    if(pq.top()< m){
        cout << -1;
    } else{
        cout << count;
    }

}