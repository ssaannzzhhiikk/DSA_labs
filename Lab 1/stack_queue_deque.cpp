#include <iostream>
using namespace std;

// ================== STACK ==================
class Stack {
private:
    int arr[1000];
    int topIndex;
public:
    Stack() { topIndex = -1; }

    void push(int x) {
        if (topIndex < 999) {
            arr[++topIndex] = x;
        } else {
            cout << "Stack overflow\n";
        }
    }

    void pop() {
        if (topIndex >= 0) {
            topIndex--;
        } else {
            cout << "Stack underflow\n";
        }
    }

    int top() {
        if (topIndex >= 0) return arr[topIndex];
        cout << "Stack is empty\n";
        return -1;
    }

    bool empty() {
        return topIndex == -1;
    }

    int size() {
        return topIndex + 1;
    }
};

// ================== QUEUE ==================
class Queue {
private:
    int arr[1000];
    int frontIndex, rearIndex, count;
public:
    Queue() {
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    void push(int x) {
        if (count < 1000) {
            rearIndex = (rearIndex + 1) % 1000;
            arr[rearIndex] = x;
            count++;
        } else {
            cout << "Queue overflow\n";
        }
    }

    void pop() {
        if (count > 0) {
            frontIndex = (frontIndex + 1) % 1000;
            count--;
        } else {
            cout << "Queue underflow\n";
        }
    }

    int front() {
        if (count > 0) return arr[frontIndex];
        cout << "Queue is empty\n";
        return -1;
    }

    int back() {
        if (count > 0) return arr[rearIndex];
        cout << "Queue is empty\n";
        return -1;
    }

    bool empty() {
        return count == 0;
    }

    int size() {
        return count;
    }
};

// ================== DEQUE ==================
class Deque {
private:
    int arr[1000];
    int frontIndex, rearIndex, count;
public:
    Deque() {
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    void push_front(int x) {
        if (count < 1000) {
            frontIndex = (frontIndex - 1 + 1000) % 1000;
            arr[frontIndex] = x;
            count++;
        } else {
            cout << "Deque overflow\n";
        }
    }

    void push_back(int x) {
        if (count < 1000) {
            rearIndex = (rearIndex + 1) % 1000;
            arr[rearIndex] = x;
            count++;
        } else {
            cout << "Deque overflow\n";
        }
    }

    void pop_front() {
        if (count > 0) {
            frontIndex = (frontIndex + 1) % 1000;
            count--;
        } else {
            cout << "Deque underflow\n";
        }
    }

    void pop_back() {
        if (count > 0) {
            rearIndex = (rearIndex - 1 + 1000) % 1000;
            count--;
        } else {
            cout << "Deque underflow\n";
        }
    }

    int front() {
        if (count > 0) return arr[frontIndex];
        cout << "Deque is empty\n";
        return -1;
    }

    int back() {
        if (count > 0) return arr[rearIndex];
        cout << "Deque is empty\n";
        return -1;
    }

    bool empty() {
        return count == 0;
    }

    int size() {
        return count;
    }
};

// ================== DEMO ==================
int main() {
    Stack st;
    st.push(10);
    st.push(20);
    cout << "Stack top: " << st.top() << endl;
    st.pop();
    cout << "Stack top after pop: " << st.top() << endl;

    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "Queue front: " << q.front() << ", back: " << q.back() << endl;
    q.pop();
    cout << "Queue front after pop: " << q.front() << endl;

    Deque dq;
    dq.push_back(5);
    dq.push_front(10);
    dq.push_back(20);
    cout << "Deque front: " << dq.front() << ", back: " << dq.back() << endl;
    dq.pop_front();
    dq.pop_back();
    cout << "Deque front after pops: " << dq.front() << endl;

    return 0;
}
