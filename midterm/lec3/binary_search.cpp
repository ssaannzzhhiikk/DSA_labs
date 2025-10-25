#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& nums, int target) {

    // Time coplexity O(log n)
    // Space complexity:
    // O(1) (iterative) or O(log n) (recursive)

    int low = 0, high = nums.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;  // avoid overflow
        
        if (nums[mid] == target) {
            return mid; // found target
        } else if (nums[mid] < target) {
            low = mid + 1; // search right half
        } else {
            high = mid - 1; // search left half
        }
    }
    
    return -1; // not found
}


int lower_bound(vector<int>& arr, int x){
    int l = 0, r = arr.size();
    while(l < r){
        int mid = (l+r) / 2;
        if(arr[mid] < x){
            l = mid + 1;
        } else{
            r = mid;
        }
    }
    return l;
}

int upper_bound(vector<int>& arr, int x){
    int l = 0, r = arr.size();
    while(l < r){
        int mid = (l+r) / 2;
        if(arr[mid] <= x){
            l = mid + 1;
        } else{
            r = mid;
        }
    }
    return l;
}

int main(){
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    
    int index = binarySearch(nums, target);
    
    if (index != -1)
        cout << "Target found at index " << index << endl;
    else
        cout << "Target not found" << endl;

    
}