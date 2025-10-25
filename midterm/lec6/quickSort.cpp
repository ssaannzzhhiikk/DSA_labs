#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[high];  // Pivot to check
    int wall = low - 1;     // Wall that moves after we find lower element

    for(int i = low; i <= high; i++){
        if(arr[i] < pivot){
            wall++;
            swap(arr[wall], arr[i]);
        }
    }

    swap(arr[wall + 1], arr[high]);
    return wall + 1;
}

void quickSort(vector<int> &arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main(){
    vector<int> arr = {3, 6, 3, 1, 8, 5, 10, 5};

    quickSort(arr, 0, arr.size());
    
}