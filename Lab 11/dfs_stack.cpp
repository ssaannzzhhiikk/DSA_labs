/*
Depth-First Search explores a graph deeply, going as far as possible along
each branch before backtracking.
Time Complexity: O(V + E)

u → the current node you are processing
v → a neighbor of u
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int start, vector<vector<int>>& adj){
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> st;

    st.push(start);

    while(!st.empty()){
        int current = st.top();
        st.pop();

        if(!visited[current]){
            visited[current] = true;
            cout << current << " ";
        }

        for(int i = adj[current].size() - 1; i >= 0; --i){
            int neighbor = adj[current][i];
            if(!visited[neighbor]){
                st.push(neighbor);
            }
        }
    }
}


/*
0 → 1, 2
1 → 3
2 → 4, 5
3 → (none)
4 → (none)
5 → (none)


Initial state
stack = [0]
visited = [false, false, false, false, false, false]

Step 1
adj[0] = [1, 2]
push 2
push 1
Stack: [2, 1]

stack pop → 1
visit 1

Step 2
stack pop → 1
visit 1

adj[1] = [3]
push 3
stack : [2, 3]

Step 3
pop → 3
visit 3
[2]

Step 4
pop → 2
visit 2

adj[2] = [4, 5]
push 5
push 4
Stack : [5, 4]

Step 5 — Pop 4
pop → 4
visit 4


No neighbors.

Stack: [5]

Step 6 — Pop 5
pop → 5
visit 5

*/