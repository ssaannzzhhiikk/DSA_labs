#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - left;

    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++) L[i] = arr[i + left];
    for(int j = 0; j < n2; j++) R[j] = arr[j + mid + 1];
    
    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2){
        if(L[i] < R[j]) arr[k++] = L[i++];
        else  arr[k++] = R[i++];
    }

    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];

}

void mergeSort(vector<int> &arr, int left, int right){
    int mid = left + (right-left) / 2;
    mergeSort(arr, left, mid - 1);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}