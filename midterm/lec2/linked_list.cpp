#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};


void insertAtHead(Node *&head, int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node*& head, int val){
    Node *newNode = new Node(val);
    if(!head) head = newNode;
    Node* temp = head;

    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertWithTail(Node*& head, Node*& tail, int val){
    Node* newNode = new Node(val);
    if(!head) head = tail = newNode; return;
    tail->next = newNode;
    tail = newNode;
}

void deleteNode(Node*& head, int key) {
    if (!head) return;

    // Удаляем первый элемент
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* t = head;
    // ищем элемент, который стоит перед удаляемым
    while (t->next && t->next->data != key) {
        t = t->next;
    }

    if (t->next) {
        Node* d = t->next;
        t->next = t->next->next;
        delete d;
    }
}


Node* reverse(Node* head){
    Node* cur = head;
    Node* next = NULL;
    Node* prev = NULL;

    while(cur != NULL){
        next = cur->next;
        cur->next = prev;

        prev = cur;
        cur = next;
    }

    return prev;
}