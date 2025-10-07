#include <bits/stdc++.h>
using namespace std;


int main(){
    long long q, k, x, sum = 0;
    string s;
    priority_queue<long long,vector<long long>,greater<long long>>pq;

    cin >> q >> k;

    for(int i = 0; i < q; i++){
        cin >> s;
        if(s =="insert"){
            cin >> x;
            if(pq.size() == k){
                long long az = pq.top();
                sum -= az;
                pq.pop();
                long long mx = max(az, x);
                pq.push(mx);
                sum+=mx;
            } else{
                pq.push(x);
                sum += x;
            }
        }

        if(s == "print"){
            cout << sum << endl;
        }
    }
}