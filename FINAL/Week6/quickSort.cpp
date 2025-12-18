#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int n = arr.size();
    int pivot = arr[high];
    int i = low-1;

    for(int j = low; low <= high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}