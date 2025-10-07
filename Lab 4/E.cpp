#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, y, z;
    cin >> n;
    int left_child[n + 1] = {0};
    int right_child[n + 1] = {0};
    queue<int> qu;

    for(int i = 0; i < n-1; i++){
        cin >> x >> y >> z;
        if(z == 0){
            left_child[x] = y;
        } else{
            right_child[x] = y;
        }
    }

    qu.push(1);
    int max_width = 0;
    while(!qu.empty()){
        int cur_level_count = qu.size();
        if(cur_level_count > max_width){
            max_width = cur_level_count;
        }
        for(int i = 0; i < cur_level_count; i++){
            int v = qu.front();
            qu.pop();
            if(left_child[v] != 0) qu.push(left_child[v]);
            if(right_child[v] != 0) qu.push(right_child[v]);
        }
    }
    cout << max_width;
}

/*

       1
     /   \
    3     2
   / \     \
  5   6     4


How it’s managed in code (the concept)

We use a queue (FIFO structure):

You start by putting the root node (1) in the queue.

While the queue isn’t empty:

Count how many nodes are currently inside it → this is 
the number of nodes in the current level.

Take each of them out (one by one).

For every node you take out, add its children (left and right)
into the queue — these will form the next level.




Queue / actions:

Start: queue = [1], max_width = 0

Iteration 1:

current_level_count = 1 → max_width = 1

Pop 1, push children 3 and 2 → queue = [3, 2]

Iteration 2:

current_level_count = 2 → max_width = 2

Pop 3, push 5 and 6 → queue = [2, 5, 6]

Pop 2, push 4 → queue = [5, 6, 4]

Iteration 3:

current_level_count = 3 → max_width = 3

Pop 5, 6, 4 → no children pushed → queue = []

Done. Final max_width = 3.
*/