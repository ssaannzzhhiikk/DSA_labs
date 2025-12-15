#include <bits/stdc++.h>
using namespace std;


int main(){
    stack<int> st;
    queue<int> q;
    deque<int> dq;

    for(int i = 0; i < 10; i++){
        st.push(i);          // last, undo, reverse, nested, parentheses, previous, backtracking
        q.push(i);           // first, earliest, level, breadth, shortest (unweighted), order preserved
        dq.push_back(i);     // Sliding Window problems
        dq.push_front(i+1);  // window, both ends, max/min, range, sliding
        
        cout << st.top() <<" "<< q.front() <<" "<< dq.back() << dq.front() << endl; 
    }

    // Stack LIFO
    // Use case: function calls, undo/redo, parentheses checking, DFS.
    stack<int> s;
    s.push(10);
    s.push(20);
    s.top();
    s.pop();  // removes 20
    s.empty();
    s.size();


    // Queue FIFO
    // Use case: BFS, scheduling, buffering.
    queue<int> q;
    q.push(10);
    q.push(20);
    q.front();  // 10
    q.back();   // 20
    q.pop();    // removes 10
    q.empty();
    q.size();


    // Both ends
    // Use case: sliding window problems, palindrome checks, Dijkstra (0-1 BFS)
    deque<int> d;
    d.push_back(10); //[ 10 ]
    d.push_front(5); //[ 5, 10 ]
    d.front();       // -> 5
    d.back();        // -> 10
    d.pop_back();    // removes 10, [5]
    d.pop_front();   // removes 5, []
    d.empty();      
    d.size();
}
    