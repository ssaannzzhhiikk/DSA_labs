#include <bits/stdc++.h>
using namespace std;


struct Node {
    string data;
    Node* next;
    Node(string val) : data(val), next(nullptr) {}
};

int main (){
    int N, K, cnt = 0;
    string s;
    cin >> N >> K;
    
    Node *head = nullptr, *tail = nullptr;
    
    for(int i = 0; i < N; i++){
        cin >> s;
        Node *newNode = new Node(s);

        if(head == nullptr) head = tail = newNode;

        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    
    Node *cur = head;
    while(cur != nullptr){
        if(cnt >= K) cout << cur->data << " ";
        cur = cur->next;
        cnt++;
    }

    cnt = 0, cur = head;
    while(cnt < K){
        cout << cur->data << " ";
        cur = cur->next;
        cnt++;
    }
}