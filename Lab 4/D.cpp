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

int subSum(Node* tar){
    if(tar == nullptr) return 0;
    else{
        cout <<  1 + tar->data + tar-> data << " ";
        return 1 + subSum(tar->left) + subSum(tar->right);
    }
}

int sum[5002];
int maxlvl = 0;

void level(Node* root, int lvl){
    if(root == NULL) return;
    sum[lvl] += root->data;
    level(root->left, lvl+1);
    level(root->right, lvl+1);
    maxlvl = max(maxlvl, lvl);
}

int main(){
    int n, x;
    Node* root = NULL;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x;
        insert(root, x);
    }

    level(root, 1);
    cout << maxlvl << endl;
    for(int i = 1; i <= maxlvl; i++){
        cout << sum[i] << " ";
    }

}