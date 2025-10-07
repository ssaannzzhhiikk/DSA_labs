#include <bits/stdc++.h>
using namespace std;



int main(){
    priority_queue<long long,vector<long long>,greater<long long>> pq;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        long long x;
        cin >> x;
        pq.push(x);
    }

    long long sum = 0;
    while(pq.size() > 1){
        long long subSum = 0;
        long long bir = pq.top();
        pq.pop();
        long long eki = pq.top();
        pq.pop();
        subSum = eki + bir;     
        pq.push(subSum);
        sum += subSum;
    }

    cout << sum;
}