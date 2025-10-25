#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && arr[l] > arr[largest]) largest = l;
    if(r < n && arr[r] > arr[largest]) largest = r;

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr){
    int n = arr.size();

    for(int i = n /2 - 1; i>=0; i--){   // constructing max heap
        heapify(arr, n, i);
    }

    for(int i = n - 1; i >= 0; i--){
        swap(arr[0], arr[i]);        // swapping max to iits position
        heapify(arr, i, 0);          // heapifying rest, where there is no max
    }
}

int main(){
    vector<int> arr = {3, 6, 3, 1, 8, 5, 10, 5};
    heapSort(arr);
}