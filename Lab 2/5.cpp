#include <bits/stdc++.h>
using namespace std;

struct Node {
    string data;
    Node *next;
    Node(string val) : data(val), next(nullptr) {}
};

int main(){
    int N;
    cin >> N;
    Node *head = nullptr, *tail = nullptr;

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        Node *newNode = new Node(s);
        if(head == nullptr) head = tail = newNode;
        else{
            tail->next = newNode;
            tail = newNode;
        }

    }

    Node *cur = head;
    vector<string> students;
    while(cur != nullptr){
        if(cur->next == nullptr || cur->next->data != cur->data){
            students.push_back(cur->data);
        }
        cur = cur->next;
    }
    reverse(students.begin(), students.end());
    cout << "All in all: " << students.size() << endl;
    cout << "Students:" << endl;
    for(string x : students){
        cout << x << endl;
    }
}


