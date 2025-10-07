#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    priority_queue<int> pq;  // max-heap

    for (int i = 0; i < n; i++) {
        int seats;
        cin >> seats;
        pq.push(seats);
    }

    long long total = 0;
    for(int i = 0; i < x ; i++){
        int bir = pq.top();
        pq.pop();
        total += bir;
        if(bir > 1) pq.push(bir-1);
    }
    cout << total;
}