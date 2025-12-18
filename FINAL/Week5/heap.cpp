#include <bits/stdc++.h>
using namespace std;

struct MaxHeap{
    vector<int> A;
    bool compare(int a, int b){return a > b;}

    void heapifyUp(int i){
        if(i == 0) return;
        int p = (i-1) / 2;

        if(compare(A[i], A[p])){
            swap(A[i], A[p]);
            heapifyUp(A[p]);
        }
    }

    void heapifyDown(int i){
        int n = A.size();
        int l = 2*i + 1;
        int r = 2*i + 2;
        int largest = i;

        if(l < n && compare(A[l], A[largest])) largest = l;
        if(r < n && compare(A[r], A[largest])) largest = r;

        if(largest != i){
            swap(A[i], A[largest]);
            heapifyDown(largest);
        }
    }

    void insert(int val){
        A.push_back(val);
        heapifyUp(A.size() - 1);
    }

    int pop(){
        if(A.empty()) throw runtime_error("Heap empty");
        
        int root = A[0];
        A[0] = A.back();
        A.pop_back();
        if(!A.empty()) heapifyDown(0);
        return root;
    }
};




int main(){
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
}