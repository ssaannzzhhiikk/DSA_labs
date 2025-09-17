#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int val): data(val), next(nullptr) {}
};

int main(){
    int n;
    cin >> n;

    Node *head = nullptr, *tail = nullptr;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        Node *newNode = new Node(a);

        if(head == nullptr) head = tail = newNode;
        else{
            tail->next = newNode; // assigning real pointrer to nullptr
            tail = newNode; // updating tails pointer
        }
    }

    map<int, int> freq;
    Node *cur = head;
    while(cur){
        freq[cur->data]++;
        cur = cur->next;
    }

    int maxFreq = 0;
    for( auto &x : freq){
        maxFreq = max(maxFreq, x.second);
    }

    vector<int> vec;
    for(auto &a : freq){
        if(a.second == maxFreq){
            vec.push_back(a.first);
        }
    }

    sort(vec.rbegin(), vec.rend());
    for(int x : vec) cout << x << " ";
    return 0;

}