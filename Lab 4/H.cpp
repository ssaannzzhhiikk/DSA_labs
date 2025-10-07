#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

void insert(Node* &root, int val){
    if(root == NULL){
        root = new Node(val);
    } else{
        if(root->data < val) insert(root->right, val);
        else insert(root->left, val);
    }
}
/*
Given the root of a binary search tree with distinct keys.
Replace the key of each node with the sum of the keys over
the nodes that has greater than or equal key. 
Print new keys in increasing order.

As a reminder, a binary search tree is a tree
that satisfies these constraints:

The left subtree of a node contains only nodes
with keys less than the node’s key.

The right subtree of a node contains only
nodes with keys greater than the node’s key.

Both the left and right subtrees must also be
binary search trees.

reverse in order traversal
*/
int sum = 0;

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->right);
    sum += root->data;
    cout << sum << " ";
    inorder(root->left);
}
int main(){
    int n, x;
    cin >> n;
    Node* root = NULL;
    for(int i = 0; i < n; i++){
        cin >> x;
        insert(root, x);
    }

    inorder(root);
    
}