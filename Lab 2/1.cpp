#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insertAtTail(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void clearList(Node*& head) {
    while (head) {
        Node* t = head;
        head = head->next;
        delete t;
    }
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        insertAtTail(head, tail, val);
    }

    int x;
    cin >> x;

    int bestIndex = 0;
    int minDist = abs(head->data - x);

    Node* temp = head->next;
    int idx = 1;

    while (temp) {
        int dist = abs(temp->data - x);
        if (dist < minDist) {
            minDist = dist;
            bestIndex = idx;
        }
        temp = temp->next;
        idx++;
    }

    cout << bestIndex << endl;

    clearList(head);
    return 0;
}
