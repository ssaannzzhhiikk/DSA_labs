#include <bits/stdc++.h>
using namespace std;

// A simple MaxHeap implementation using vector<int>

struct MaxHeap{
    vector<int> A;

    bool compare(int a, int b) {return a > b;}
    // return a<b; for minHeap
    void heapifyUp(int i) {
        if (i == 0) return;  // Base case: reached the root

        int p = (i - 1) / 2;
        if (compare(A[i], A[p])) {
            swap(A[i], A[p]);
            heapifyUp(p); // Recursive call
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
        if (!A.empty()) heapifyDown(0);
        return root;
    }

    int peek() const {
        if (A.empty()) throw runtime_error("Heap empty");
        return A[0];
    }

    void buildHeap(vector<int> &input){
        A = input;
        for (int i = (int)A.size()/2 - 1; i >= 0; --i)
            heapifyDown(i);
    }

    bool empty() const { return A.empty(); }
    int size() const { return A.size(); }
};



int main() {
    MaxHeap heap;

    // Inserting values
    heap.insert(10);
    heap.insert(4);
    heap.insert(15);
    heap.insert(20);
    heap.insert(8);

    cout << "Heap after insertions (internal array): ";
    for(int x : heap.A) cout << x << " ";
    cout << "\n";

    // Peek at the maximum
    cout << "Current Max (peek): " << heap.peek() << "\n";

    // Extract (pop) elements one by one
    cout << "Popping elements in descending order: ";
    while (!heap.empty()) {
        cout << heap.pop() << " ";
    }
    cout << "\n";

    // Build heap directly from array
    vector<int> arr = {3, 12, 7, 1, 9, 5};
    heap.buildHeap(arr);

    cout << "Heap after buildHeap: ";
    for(int x : heap.A) cout << x << " ";
    cout << "\n";

    return 0;
}