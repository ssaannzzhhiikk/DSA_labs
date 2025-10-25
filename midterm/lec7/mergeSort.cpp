#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right){
    // Sizes of vector
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Creating vectors to seperate
    vector<int> L(n1), R(n2);

    // Inserting their values
    for(int i = 0; i < n1; i++) L[i] = arr[left + i];
    for(int i = 0; i < n2; i++) R[i] = arr[mid + i + 1];

    // Merging back to array
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(L[i] < R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    // merging the rest
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int> &arr, int left, int right){
    if(left >= right) return;

    int mid = left + (right - left);
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


int main() {
    vector<int> arr = {5, 2, 4, 6, 1, 3};
    mergeSort(arr, 0, arr.size() - 1);

    for (int x : arr) cout << x << " ";
    return 0;
}