#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> L(n1), R(n2);
    for(int i = 0; i < n1; i++) L[i] = arr[l + i];
    for(int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(i < n1 && j < n2){
            if(L[i] <= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        } 
    }
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int> &arr, int l, int r) {
    if(l >= r) return;
    int mid = l + (r-l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
}

int main() {
    vector<int> arr = {8, 3, 5, 1, 4, 7, 2, 6};
    mergeSort(arr, 0, arr.size() - 1);

    for(int x : arr) cout << x << " ";
}