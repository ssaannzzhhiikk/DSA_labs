#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

void insert(Node* &root, int val) {
    if(root == NULL) {
        root = new Node(val);
        return;
    }
    if(val < root->val) insert(root->left, val);
    else if(val > root->val) insert(root->right, val);
}

int diameter = 0;

int depth(Node* root) {
    if(root == NULL) return 0;           // базовый случай
    int L = depth(root->left);           // глубина левого поддерева
    int R = depth(root->right);          // глубина правого поддерева
    diameter = max(diameter, L + R);     // обновляем глобальный диаметр
    return 1 + max(L, R);                // возвращаем глубину текущего узла
}

int main() {
    int n, x;
    cin >> n;

    Node* root = NULL;
    for(int i = 0; i < n; i++) cin >> x, insert(root, x);

    depth(root);
    cout << diameter + 1 << "\n";

    return 0;
}