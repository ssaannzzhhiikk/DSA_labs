#include <bits/stdc++.h>
using namespace std;

int main(){
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