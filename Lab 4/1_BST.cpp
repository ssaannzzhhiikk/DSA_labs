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

// Find how many sub trees in a root
int subTree(Node* root){
    if(root == NULL) return 0;
    else{
        return 1 + subTree(root->left) + subTree(root->right);
    }
}

// Recursive Traversals
void inorder(Node* root) {            // Left → Root → Right
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {           // Root → Left → Right
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {          // Left → Right → Root
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node* root) {         // BFS (Using Queue)
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();
        cout << cur->data << " ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}

int main() {
    Node* root = nullptr;
    vector<int> values = {5, 3, 7, 2, 4, 8};

    for (int v : values) root = insert(root, v);

    cout << "Inorder    : "; inorder(root); cout << "\n";
    cout << "Preorder   : "; preorder(root); cout << "\n";
    cout << "Postorder  : "; postorder(root); cout << "\n";
    cout << "Level Order: "; levelOrder(root); cout << "\n";

    return 0;
}
