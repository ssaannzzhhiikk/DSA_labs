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

Node* insert(Node*&root, int val){
    if(root == NULL){
        return new Node(val);
    }

    if (root->data == val){
        return root;
    }

    if(root->data < val){
        root->right = insert(root->right, val);
    } else{
        root->left = insert(root->left, val);
    }

    return root;
}

int subTree(Node* root){
    if(root == NULL) return;
    else{
        return 1 + subTree(root->left) + subTree(root->right);
    }
}

Node* search(Node* root, int key){
    if(root==NULL || root->data == key) return root;

    if(root->data < key) search(root->right, key);
    
    else search(root->left, key);
}

// traversals
void printInorder(Node* root){  // left root right
    if(!root) root;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

void printPreorder(Node* root){ // root left right
    if(!root) return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(Node* root){ // Left  Right  Root
    if(!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}


Node* buildBalanced(vector<int>& arr, int l, int r) {  // vector should came sorted
    if (l > r) return NULL;

    int mid = l + (r - l) / 2;
    Node* root = new Node(arr[mid]);

    root->left = buildBalanced(arr, l, mid - 1);
    root->right = buildBalanced(arr, mid + 1, r);

    return root;
}

void bfs(Node* root){
    if (!root) return;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* cur = q.front();
        q.pop();

        cout << cur->data << " ";

        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
}


int main(){

}