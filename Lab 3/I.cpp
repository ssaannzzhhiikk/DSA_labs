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



int main(){
    int n, x;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    cin >> x;

    if(binarySearch(vec, x) == -1){
        cout << "No";
    } else {
        cout << "Yes";
    }

}