#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

int main(){
    int n, dt, pos, ind = 0;
    cin >> n;

    Node *head = nullptr, *tail = nullptr;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;

        Node *newNode = new Node(a);
        if(head == nullptr) head = tail = newNode;
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    cin >> dt;
    cin >> pos;

    Node *cur = head;
    while(cur != nullptr){
        if(ind == pos){
            cout << dt << " ";
        }
        cout << cur->data << " ";
        cur = cur->next;
        ind++;
    }
}