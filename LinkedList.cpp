/*
 * Comprehensive Linked List Implementation
 * 
 * This file contains various linked list algorithms and operations including:
 * - Basic operations: insert, delete, search, display
 * - Advanced algorithms: reverse, detect cycle, find middle, merge sorted lists
 * - Utility functions: length calculation, nth node from end
 * 
 * Data Structure: Singly Linked List
 */

#include <bits/stdc++.h>
using namespace std;

// Node structure for singly linked list
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// ==================== BASIC OPERATIONS ====================

// Insert a node at the head of the list
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Insert a node at the tail of the list
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert a node at a specific position (0-indexed)
void insertAtPosition(Node*& head, int val, int pos) {
    if (pos == 0) {
        insertAtHead(head, val);
        return;
    }
    Node* newNode = new Node(val);
    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp; i++) {
        temp = temp->next;
    }
    if (!temp) {
        cout << "Position out of bounds\n";
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete a node with a specific value
void deleteNode(Node*& head, int key) {
    if (!head) return;
    
    // If head needs to be deleted
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    // Find the node before the one to delete
    Node* temp = head;
    while (temp->next && temp->next->data != key) {
        temp = temp->next;
    }
    
    if (temp->next) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

// Delete node at a specific position (0-indexed)
void deleteAtPosition(Node*& head, int pos) {
    if (!head) return;
    
    if (pos == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp; i++) {
        temp = temp->next;
    }
    
    if (!temp || !temp->next) {
        cout << "Position out of bounds\n";
        return;
    }
    
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

// Search for a value in the list
bool search(Node* head, int key) {
    Node* temp = head;
    while (temp) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

// Display the linked list
void printList(Node* head) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

// Get the length of the list
int getLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

// ==================== ADVANCED ALGORITHMS ====================

// Reverse the linked list (Iterative)
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

// Reverse the linked list (Recursive)
Node* reverseRecursive(Node* head) {
    if (!head || !head->next) return head;
    
    Node* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    
    return newHead;
}

// Find the middle node of the list (Floyd's Tortoise and Hare)
Node* findMiddle(Node* head) {
    if (!head) return nullptr;
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

// Detect if the list has a cycle
bool hasCycle(Node* head) {
    if (!head) return false;
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) return true;
    }
    
    return false;
}

// Find the starting point of a cycle (if exists)
Node* detectCycleStart(Node* head) {
    if (!head) return nullptr;
    
    Node* slow = head;
    Node* fast = head;
    
    // Detect cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            // Cycle detected, find start
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    
    return nullptr; // No cycle
}

// Get nth node from the end (1-indexed)
Node* getNthFromEnd(Node* head, int n) {
    if (!head) return nullptr;
    
    Node* first = head;
    Node* second = head;
    
    // Move first pointer n steps ahead
    for (int i = 0; i < n; i++) {
        if (!first) return nullptr;
        first = first->next;
    }
    
    // Move both pointers until first reaches end
    while (first) {
        first = first->next;
        second = second->next;
    }
    
    return second;
}

// Remove nth node from end (1-indexed)
void removeNthFromEnd(Node*& head, int n) {
    Node* dummy = new Node(0);
    dummy->next = head;
    
    Node* first = dummy;
    Node* second = dummy;
    
    // Move first pointer n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        if (!first) {
            delete dummy;
            return;
        }
        first = first->next;
    }
    
    // Move both pointers
    while (first) {
        first = first->next;
        second = second->next;
    }
    
    // Delete the nth node
    if (second->next) {
        Node* toDelete = second->next;
        second->next = second->next->next;
        delete toDelete;
    }
    
    head = dummy->next;
    delete dummy;
}

// Merge two sorted linked lists
Node* mergeSortedLists(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    
    Node* dummy = new Node(0);
    Node* current = dummy;
    
    while (l1 && l2) {
        if (l1->data <= l2->data) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    
    // Attach remaining nodes
    current->next = l1 ? l1 : l2;
    
    Node* result = dummy->next;
    delete dummy;
    return result;
}

// Remove duplicates from sorted list
void removeDuplicates(Node* head) {
    if (!head) return;
    
    Node* current = head;
    while (current && current->next) {
        if (current->data == current->next->data) {
            Node* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate;
        } else {
            current = current->next;
        }
    }
}

// Check if list is palindrome
bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;
    
    // Find middle
    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse second half
    Node* secondHalf = reverse(slow->next);
    
    // Compare both halves
    Node* firstHalf = head;
    Node* temp = secondHalf;
    bool result = true;
    
    while (temp) {
        if (firstHalf->data != temp->data) {
            result = false;
            break;
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }
    
    // Restore list (optional)
    slow->next = reverse(secondHalf);
    
    return result;
}

// Rotate list to the right by k positions
Node* rotateRight(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;
    
    // Calculate length and connect tail to head
    Node* tail = head;
    int length = 1;
    while (tail->next) {
        tail = tail->next;
        length++;
    }
    tail->next = head;
    
    // Find new tail position
    k = k % length;
    int stepsToNewTail = length - k;
    
    Node* newTail = head;
    for (int i = 1; i < stepsToNewTail; i++) {
        newTail = newTail->next;
    }
    
    Node* newHead = newTail->next;
    newTail->next = nullptr;
    
    return newHead;
}

// Free all memory allocated for the list
void clearList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// ==================== MAIN FUNCTION (DEMONSTRATION) ====================

int main() {
    Node* head = nullptr;
    
    cout << "=== Linked List Operations Demo ===\n\n";
    
    // Basic insertions
    cout << "1. Inserting elements: 10, 20, 30, 40, 50\n";
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    cout << "List: ";
    printList(head);
    cout << "Length: " << getLength(head) << "\n\n";
    
    // Insert at head
    cout << "2. Insert 5 at head\n";
    insertAtHead(head, 5);
    cout << "List: ";
    printList(head);
    cout << "\n";
    
    // Insert at position
    cout << "3. Insert 25 at position 4\n";
    insertAtPosition(head, 25, 4);
    cout << "List: ";
    printList(head);
    cout << "\n";
    
    // Search
    cout << "4. Search for 30: " << (search(head, 30) ? "Found" : "Not Found") << "\n";
    cout << "   Search for 100: " << (search(head, 100) ? "Found" : "Not Found") << "\n\n";
    
    // Find middle
    Node* middleNode = findMiddle(head);
    cout << "5. Middle element: " << (middleNode ? to_string(middleNode->data) : "NULL") << "\n\n";
    
    // Nth from end
    Node* nthNode = getNthFromEnd(head, 3);
    cout << "6. 3rd node from end: " << (nthNode ? to_string(nthNode->data) : "NULL") << "\n\n";
    
    // Delete a node
    cout << "7. Delete node with value 25\n";
    deleteNode(head, 25);
    cout << "List: ";
    printList(head);
    cout << "\n";
    
    // Reverse the list
    cout << "8. Reverse the list\n";
    head = reverse(head);
    cout << "List: ";
    printList(head);
    cout << "\n";
    
    // Reverse back
    cout << "9. Reverse back to original\n";
    head = reverseRecursive(head);
    cout << "List: ";
    printList(head);
    cout << "\n";
    
    // Test palindrome
    Node* palindromeList = nullptr;
    insertAtTail(palindromeList, 1);
    insertAtTail(palindromeList, 2);
    insertAtTail(palindromeList, 3);
    insertAtTail(palindromeList, 2);
    insertAtTail(palindromeList, 1);
    cout << "10. Check palindrome for list: ";
    printList(palindromeList);
    cout << "    Is palindrome: " << (isPalindrome(palindromeList) ? "Yes" : "No") << "\n\n";
    
    // Merge two sorted lists
    Node* list1 = nullptr;
    Node* list2 = nullptr;
    insertAtTail(list1, 1);
    insertAtTail(list1, 3);
    insertAtTail(list1, 5);
    insertAtTail(list2, 2);
    insertAtTail(list2, 4);
    insertAtTail(list2, 6);
    
    cout << "11. Merge two sorted lists:\n";
    cout << "    List 1: ";
    printList(list1);
    cout << "    List 2: ";
    printList(list2);
    Node* merged = mergeSortedLists(list1, list2);
    cout << "    Merged: ";
    printList(merged);
    cout << "\n";
    
    // Clean up
    clearList(head);
    clearList(palindromeList);
    clearList(merged);
    
    cout << "All operations completed successfully!\n";
    
    return 0;
}
