#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int x){
    int low = 0;
    int high = arr.size() - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == x) return mid;
        else if(arr[mid] < x) low+= mid + 1;
        else high = mid - 1;
    }

    return -1;
}

int lowerBound(vector<int> &arr, int x){
    int low = 0;
    int high = arr.size() - 1;

    while(low < high){
        int mid = low + (high - low) / 2;
        if(arr[mid] < x) low = mid + 1;
        else high = mid - 1; 
    }
    return low;
}

int lowerBound(vector<int> &arr, int x){
    int low = 0;
    int high = arr.size() - 1;

    while(low < high){
        int mid = low + (high - low) / 2;
        if(arr[mid] <= x) low = mid + 1;
        else high = mid - 1; 
    }
    return low;
}