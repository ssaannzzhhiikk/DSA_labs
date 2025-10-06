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


int main(){
    int N, X, x;
    Node* root = nullptr;
    cin >> N;

    for(int i = 0 ; i < N; i++){
        cin >> x;
        insert(root, x);
    }
    
    cin >> X;
    

}