#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &nums, int target){
    int low = 0, high = nums.size() - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        
        if(nums[mid] == target){
            return mid;
        } else if(nums[mid] < target ){
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n, q, l1, r1, l2, r2;
    cin >> n >> q;
    vector<int> vec(n);
    map<int, int> inds;

    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());


    for(int i = 0; i < q; i++){
        cin >> l1 >> r1 >> l2 >> r2;
        int l = max(l1, l2);
        int r = min(r1, r2);

        int c1 = upper_bound(vec.begin(), vec.end(), r1) 
            - lower_bound(vec.begin(), vec.end(), l1);

        int c2 = upper_bound(vec.begin(), vec.end(), r2) 
            - lower_bound(vec.begin(), vec.end(), l2);

        int c3 = 0;
        if(l <= r){
            c3 = upper_bound(vec.begin(), vec.end(), r) 
            - lower_bound(vec.begin(), vec.end(), l);
        }

        cout << c1 + c2 - c3 << "\n";
    }

}