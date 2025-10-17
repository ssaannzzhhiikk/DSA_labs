#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    int mini = INT_MAX;

    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    for(int i = 1; i < n; i++) mini = min(mini, abs(arr[i] - arr[i-1]));

     for(int i = 1; i < n; i++){
        if(abs(arr[i] - arr[i-1]) == mini) cout << arr[i-1] << ' ' << arr[i] << ' ';
    }
}