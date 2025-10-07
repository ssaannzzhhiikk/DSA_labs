#include <bits/stdc++.h>
using namespace std;

void balanced(vector<int> &arr, int l, int r){
    if(l > r) return;
    int mid = l + (r - l) / 2;
    cout << arr[mid] << " ";
    balanced(arr, l, mid-1);
    balanced(arr, mid+1, r);
}

int main(){
    int n;
    cin >> n;
    int len = pow(2, n) - 1;
    vector<int> arr(len);
    for(int i = 0; i < len; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    balanced(arr, 0, len - 1);

}