/*
In C++, a linked list is a linear data structure
that allows the users to store data in non-contiguous memory locations.
A linked list is defined as a collection of nodes
where each node consists of two members which represents its 
value and a next/previous pointer which stores the address for the next/previous node.


Types on Linked List:
    Singly Linked List
    Doubly Linked List
    Circular Linked List
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insertAtHead(Node*& head, int val){
  Node* newNode = new Node(val);
  newNode->next = head;
  head = newNode;
}

void insertAtTail(Node*& head, int val){
  Node* newNode = new Node(val);
  if(!head) { head = newNode; return; }
  Node* temp = head;
  while (temp->next) temp = temp->next;
  temp->next = newNode;
}

void insertAtTail(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void printList(Node* head) {
  Node* temp = head;
  while (temp) { cout << temp->data << " -> "; temp = temp->next; }
  cout << "NULL\n";
}

void deleteNode(Node*& head, int key) {
  if (!head) return;
  if (head->data == key) { Node* d = head; head = head->next; delete d; return; }
  Node* t = head;
  while (t->next && t->next->data != key) t = t->next;
  if (t->next) { Node* d = t->next; t->next = t->next->next; delete d; }
}

void clearList(Node*& head){
  while(head){ Node* t=head; head=head->next; delete t; }
}



int main(){
  Node *head, *tail = nullptr;          // empty list
  insertAtHead(head, 20);        // 20
  insertAtHead(head, 10);        // 10 -> 20
  insertAtTail(head, 30);        // 10 -> 20 -> 30
  insertAtTail(head, tail, 25);
  printList(head);

  deleteNode(head, 20);          // 10 -> 30
  printList(head);

  clearList(head);               // free memory
}
