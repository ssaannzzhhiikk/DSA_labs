#include <bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> vec(n);

    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    long long low = *max_element(vec.begin(), vec.end());
    long long high = accumulate(vec.begin(), vec.end(), 0LL);
    long long ans = high;

    if(k >= n){
        cout << low;
        return 0;
    }

    while(low <= high){
        long long mid = low + (high - low) / 2;

        long long sum = 0;
        int block = 1;
        for(int i = 0; i < n; i++){
            if(sum + vec[i] > mid){
                block++;
                sum = 0;                
            }
            sum += vec[i];
        }

        if(block <= k){
            ans = mid;
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }

    cout << ans;
}


/*The greedy check function

To check if mid works:

Go through the array from left to right, accumulating sums.

If adding the next house makes the block exceed mid, start a new block.

Count how many blocks you made.

If the number of blocks > K → mid is too small.*/