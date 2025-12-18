#include <bits/stdc++.h>
using namespace std;

void heapifyDown(vector<int> &arr, int i){
    int n = arr.size();
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && arr[l] > arr[largest]) largest = l;
    if(r < n && arr[r] > arr[largest]) largest = r;
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapifyDown(arr, largest);
    }
}

void heapSort(vector<int> &arr){
    int n = arr.size();
    for(int i = n/2 - 1; i >= 0; i--){
        heapifyDown(arr, i);
    }

    for(int i = n-1; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapifyDown(arr, i);
    }
}