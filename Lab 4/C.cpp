#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL){} 
};

void insert(Node* &root, int val){
    if(root == NULL){
        root = new Node(val);
    } else{
        if(root->data < val) insert(root->right, val);
        else insert(root->left, val);
    }
}

Node* search(Node* root, int target){
    if(root == nullptr || root->data == target) return root;
    else if(root->data < target) return search(root->right, target);
    else return search(root->left, target);
}

void preorder(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int n, k, x;
    Node* root = NULL;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        insert(root, x);
    }
    cin >> x;

    Node* target = search(root, x);
    preorder(target);

}