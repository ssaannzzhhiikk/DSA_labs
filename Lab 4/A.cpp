#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val): data(val), left(nullptr), right(nullptr) {}
};

void insert(Node* &root, int val){
    if(root == nullptr){
        root = new Node(val);
        return;
    } else{
        if(val < root->data) insert(root->left, val);
        else insert(root->right, val);
    }
}

bool check(string s, Node* root){
    Node* cur = root;
    for(int i = 0; i < s.size(); i++){
        if(cur == nullptr) return false;
        else if(s[i] == 'L'){
            cur = cur->left;
        } else{
            cur = cur->right;
        }
    }
    if(cur != nullptr) return true;
    else return false;
}

int main(){
    int N, M, x;
    cin >> N >> M;
    string s;
    Node* root = nullptr;
    for(int i = 0; i < N; i++){
        cin >> x;
        insert(root, x);
    }

    for(int i = 0; i < M; i++){
        cin >> s;
        if(check(s, root)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}