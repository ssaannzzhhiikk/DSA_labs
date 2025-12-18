#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};


Node* insert(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    }
    if(head->data == val){
        return head;
    } 
    if(head->data > val){
        head->left = insert(head->left, val);
    } else{
        head->right =  insert(head->right, val);
    }
    return head;
}

int subTree(Node* head){
    if(head == NULL) return 0;
    else{
        return 1 + subTree(head->left) + subTree(head->right);
    }
}


void inorder(Node* root){  // left root right
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root){ // root left right
    if(root == NULL) return ;
    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
}

void postorder(Node* root) { // left right root
    if(root==NULL) return;
    inorder(root->left);
    inorder(root->right);
    cout << root->data << " ";
}