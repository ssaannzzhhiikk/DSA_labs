#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr){}
};

void insert(Node* &root, int val){
    if(root == nullptr){
        root = new Node(val);
    } else{
        if(val < root->data) insert(root->left, val);
        else insert(root->right, val);
    }
}

Node* search(Node* root, int key){
    if(root == nullptr || root->data == key) return root;
    if(root->data < key) return search(root->right, key);
    else return search(root->left, key);
}

int subTree(Node* tar){
    if(tar == nullptr) return 0;
    else{
        return 1 + subTree(tar->left) + subTree(tar->right);
    }
}

int main(){
    int N, X, x;
    Node* root = nullptr;
    cin >> N;

    for(int i = 0 ; i < N; i++){
        cin >> x;
        insert(root, x);
    }
    
    cin >> X;
    Node* tar = search(root, X);
    cout << subTree(tar);

}