#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};


void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    if (head != nullptr)
        head->prev = newNode;
    head = newNode;
}

void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}


void deleteNode(Node*& head, int val) {
    if (head == nullptr) return;

    Node* temp = head;

    // if deleting head
    if (temp->data == val) {
        head = temp->next;
        if (head != nullptr) head->prev = nullptr;
        delete temp;
        return;
    }

    // find the node
    while (temp != nullptr && temp->data != val)
        temp = temp->next;

    if (temp == nullptr) return; // not found

    // rewire links
    if (temp->next != nullptr)
        temp->next->prev = temp->prev;
    if (temp->prev != nullptr)
        temp->prev->next = temp->next;

    delete temp;
}




void printForward(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printBackward(Node* head) {
    if (!head) return;

    Node* temp = head;
    while (temp->next) temp = temp->next; // move to tail

    while (temp) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}
