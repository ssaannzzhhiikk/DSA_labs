Lecture 1
Complexity and Memory
Prime factorization
GCD, Sieve of Eratosthenes
Stack
Queue
Deque

Lecture 2
Linked List
Doubly Linked List

Lecture 3 
Binary Search

| Lecture 1                                                                                                                                                             | Lecture 2                                   | Lecture 3     |
| --------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------- | ------------- |
| [[#Time and Space complexity]]<br>[[#✅ GCD]]<br>[[#✅ Prime Factorization]],<br>[[#✅ Sieve of Eratosthens]]<br>[[#✅ Stack (LIFO)]],  [[#✅ Queue (FIFO)]], [[#✅ Deque]] | [[#✅ Linked List]]  [[#Doubly Linked List]] | Binary Search |
## Time and Space complexity

**Time Complexity:** he time complexity of an algorithm quantifies the amount of time taken by an algorithm to run as a function of the length of the input. Note that the time to run is a function of the length of the input and not the actual execution time of the machine on which the algorithm is running on.

The **space complexity** of an algorithm quantifies the amount of space taken by an algorithm to run as a function of the length of the input. Consider an example: Suppose a problem to find the frequency of array elements.
It is the amount of memory needed for the completion of an algorithm.

---

## ✅ GCD:

The **GCD** of two integers `a` and `b` is the largest number that divides both of them.

**Time Complexity:** O(log(min(a, b)))
**Space Complexity:** **O(1)** (iterative)  ,  **O(log(min(a, b)))** (recursive)
Euclidean Algorithm:
-  If ==b = 0 ==, then ==GCD(a, b) = a==
- Otherwise, ==GCD(a, b) = GCD(b, a % b)==

```cpp
int gcd(int a, int b) {
    while (b != 0) {
        a = a % b;
        swap(a, b);
    }
    return a;
}
```

---

## ✅ Prime Factorization:
To find all prime factors of number **N**,  we repetadly divide it by the smallest possible prime.
**Time Complexity:** **O(√n)** in worst case
**Space Complexity: O(1)**
Efficient method:
1. **Divide by 2** while possible.
2. Then try **odd numbers from 3 to sqrt(n)**.
3. If after all divisions `n > 1`, then `n` itself is a **prime factor**.

```cpp
void primeFactorization(int n) {
    // Step 1: Extract factors of 2
    while (n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }

    // Step 2: Extract odd factors
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    // Step 3: If remaining n > 1, it is prime
    if (n > 1) {
        cout << n << " ";
    }
}
```

---

## ✅ Sieve of Eratosthens:
The **Sieve of Eratosthenes** is an efficient algorithm to find **all prime numbers up to a given number `N`**
### 🧠 How it works (Step-by-Step)

1. Create an array `isPrime[0..N]` and initially mark all numbers as **true (prime)**.
2. **Mark 0 and 1 as non-prime.**
3. Starting from **i = 2**:
    - If `isPrime[i]` is true, then mark **all multiples of i (i_i, i_i+i, ... up to N)** as **false (not prime)**.
4. Continue up to `i*i ≤ N`.

Why start marking from `i * i`?  
Because any smaller composite would already have been marked by a smaller prime earlier.
-  **Time Complexity: O(N * Log(Log(N)))**
-  **Space Complexity: O(N)**

Code:
```cpp
void sieve(int N) {
    vector<bool> isPrime(N + 1, true);

    isPrime[0] = isPrime[1] = false; // 0 and 1 are not primes

    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    cout << "Primes up to " << N << ": ";
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}
```


---

## ✅ Stack (LIFO):

A stack is a linear data structure where insertion and deletion happens only at one end(top)
**Operation: push(x), pop(), top()**

Time Complexity:
**Push - Pop - Top:**  **O(1)**
**Space:** **O(N)**

## ✅ Queue (FIFO):

A queue allows insertion at **rear** and deletion from **front**.
**push(x) - pop() - front() : O(1)**
**Space: O(N)**


## ✅ Deque:
Deque allows insertion & deletion at **both front and back**.
**push(), pop(), front(), back() : O(1)**
**Space: O(N)**

| Structure | Access Type | Best For                     | Key Property                |
| --------- | ----------- | ---------------------------- | --------------------------- |
| **Stack** | LIFO        | Backtracking, Undo, DFS      | Last added → first removed  |
| **Queue** | FIFO        | BFS, Scheduling              | First added → first removed |
| **Deque** | Both ends   | Sliding windows, Palindromes | Flexible insert/remove      |

```cpp
#include <iostream>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int main() {

    // ===== STACK (LIFO) =====
    cout << "Stack (LIFO): ";
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";

    // ===== QUEUE (FIFO) =====
    cout << "Queue (FIFO): ";
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";

    // ===== DEQUE (Double-Ended Queue) =====
    cout << "Deque (Push front & back): ";
    deque<int> dq;
    dq.push_back(20);
    dq.push_front(10);
    dq.push_back(30);

    while (!dq.empty()) {
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << "\n";

    return 0;
}
```


---

## ✅ Linked List:
Linked list is a fundamental DS in CS. It mainly allows efficent insertion and deletion operations compared to arrays. Like arrays, it is also used to implement other data structures like stack, queue and deque. 
https://www.geeksforgeeks.org/dsa/linked-list-data-structure/

### Singly Linked List:
Is consist of nodes, every node collects the **data** and **pointer** to next value.
`[Data | Next] -> [Data | Next] -> [Data | Next] -> NULL`
```cpp
struct Node{
	int data;
	Node* next;
	Node(int val): data(val), next(nullptr){}
}
```

| Operation       | Description               | Time     |
| --------------- | ------------------------- | -------- |
| Insert at Head  | Add a node at beginning   | O(1)     |
| Insert at Tail  | Traverse to last & attach | O(n)     |
| Delete Value    | Search node & unlink      | O(n)     |
| Search          | Traverse one by one       | O(n)     |
| Access by Index | No random access          | ❌ (O(n)) |
### Doubly Linked List:
It is more complicated data, but gives us an advantage to traversal of the list on both directions.
It means that Node consists of 2 Node: **prev** and **next**, and **data** itself.
```cpp
struct Node{
	int data;
	Node* next;
	Node* prev;
	Node(int val): data(val), next(nullptr), prev(nullptr){}
};
```
`NULL <- [Prev | Data | Next] <-> [Prev | Data | Next] <-> [Prev | Data | Next] -> NULL`

| Feature                        | Singly              | Doubly |
| ------------------------------ | ------------------- | ------ |
| Backward Traversal             | ❌ No                | ✅ Yes  |
| Memory Usage                   | Low                 | Higher |
| Delete Node (if pointer given) | ❌ O(n) to find prev | ✅ O(1) |

Example:
```cpp
#include <iostream>
using namespace std;

// ===========================
// Singly Linked List
// ===========================
struct SNode {
    int data;
    SNode* next;
    SNode(int v) : data(v), next(nullptr) {}
};

class SinglyLinkedList {
public:
    SNode* head;
    SNode* tail;

    SinglyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert at head - O(1)
    void insertHead(int value) {
        SNode* newNode = new SNode(value);
        newNode->next = head;
        head = newNode;
        if (!tail) tail = head;
    }

    // Insert at tail - O(1) because tail pointer exists
    void insertTail(int value) {
        SNode* newNode = new SNode(value);
        if (!head) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Delete by value - O(n)
    void deleteValue(int value) {
        if (!head) return;
        if (head->data == value) {
            SNode* tmp = head;
            head = head->next;
            delete tmp;
            if (!head) tail = nullptr;
            return;
        }
        SNode* curr = head;
        while (curr->next && curr->next->data != value)
            curr = curr->next;
        if (curr->next) {
            SNode* tmp = curr->next;
            curr->next = curr->next->next;
            if (tmp == tail) tail = curr;
            delete tmp;
        }
    }

    void print() {
        SNode* temp = head;
        while (temp) { cout << temp->data << " -> "; temp = temp->next; }
        cout << "NULL\n";
    }
};

// ===========================
// Doubly Linked List
// ===========================
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int v) : data(v), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    DNode* head;
    DNode* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert at head - O(1)
    void insertHead(int value) {
        DNode* newNode = new DNode(value);
        if (!head) head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at tail - O(1)
    void insertTail(int value) {
        DNode* newNode = new DNode(value);
        if (!head) head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Delete by value - O(n)
    void deleteValue(int value) {
        DNode* curr = head;
        while (curr && curr->data != value) curr = curr->next;
        if (!curr) return;
        if (curr == head) head = head->next;
        if (curr == tail) tail = tail->prev;
        if (curr->prev) curr->prev->next = curr->next;
        if (curr->next) curr->next->prev = curr->prev;
        delete curr;
    }

    void printForward() {
        DNode* temp = head;
        while (temp) { cout << temp->data << " <-> "; temp = temp->next; }
        cout << "NULL\n";
    }

    void printBackward() {
        DNode* temp = tail;
        while (temp) { cout << temp->data << " <-> "; temp = temp->prev; }
        cout << "NULL\n";
    }
};

// ===========================
// Main
// ===========================
int main() {
    cout << "=== Singly Linked List ===\n";
    SinglyLinkedList sll;
    sll.insertHead(3);
    sll.insertHead(2);
    sll.insertTail(4);
    sll.insertTail(5);
    sll.print();
    sll.deleteValue(4);
    sll.print();

    cout << "\n=== Doubly Linked List ===\n";
    DoublyLinkedList dll;
    dll.insertHead(10);
    dll.insertHead(9);
    dll.insertTail(11);
    dll.insertTail(12);
    dll.printForward();
    dll.deleteValue(11);
    dll.printForward();
    dll.printBackward();

    return 0;
}

```


---

## ✅ Binary Search:
**Binary Search** is a [searching algorithm](https://www.geeksforgeeks.org/dsa/searching-algorithms/) that operates on a sorted or monotonic search space, repeatedly dividing it into halves to find a target value or optimal answer in logarithmic time O(log N).

|Version|Time Complexity|Space Complexity|
|---|---|---|
|Iterative|**O(log n)**|**O(1)**|
|Recursive|**O(log n)**|**O(log n)** (due to recursion stack)|

```cpp
int binarySearch(vector<int> &arr, int target){
	int low = 0;
	int high = arr.size() - 1;
	
	while(low <= high){
		int mid = low + (high - low) / 2;
		
		if(arr[mid] == target){
			return mid;
		} 
		else if(nums[mid] < target){
			low = mid + 1;
		} else{
			high = mid - 1;
		}
	}
	return -1;
}
```