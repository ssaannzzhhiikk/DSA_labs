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

int main(){
    int n, x;
    cin >> n;
    Node* root = NULL;
    for(int i = 0; i < n; i++){
        cin >> x;
        insert(root, x);
    }

    
}