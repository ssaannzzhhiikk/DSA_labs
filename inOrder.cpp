#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int item){
        data = item;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* &node, int key){
    if(node == NULL){
        return new Node(key);
    }

    if (node->data == key){
        return node;
    }

    if (node->data < key)
        node -> right = insert(node->right, key);
    else
        node->left = insert(node->left, key);

    return node;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void inorderInsert(Node* root, Node* &root2) {
    if (root == nullptr) return;
    inorderInsert(root->left, root2);
    root2 = insert(root2, root->data);
    inorderInsert(root->right, root2);
}

int main(){
    int n, x;
    cin >> n;
    Node* root = NULL;
    Node* root2 = NULL;

    for(int i = 0; i < n; i ++){
        cin >> x;
        root = insert(root, x);
    }

    inorderInsert(root, root2);

    inorder(root2); // ✅ Should print sorted order
}
