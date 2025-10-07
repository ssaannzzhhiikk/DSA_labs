#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* getMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* add(Node* root, int data) {
    if (root == NULL)
        return new Node(data);
    else if (root->data > data)
        root->left = add(root->left, data);
    else if (root->data < data)
        root->right = add(root->right, data);
    return root;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL)
        return NULL;
    else if (root->data > data)
        root->left = deleteNode(root->left, data);
    else if (root->data < data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else {
            Node* temp = getMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

Node* find(Node* root, int x) {
    if (root == NULL)
        return NULL;
    else if (root->data == x)
        return root;
    else if (root->data < x)
        return find(root->right, x);
    else
        return find(root->left, x);
}

int main() {
    int n, x;
    string query;
    cin >> n;
    Node* root = NULL;
    int duplicate[1002] = {0};

    for (int i = 0; i < n; i++) {
        cin >> query >> x;
        if (query == "insert") {
            root = add(root, x);
            duplicate[x]++;
        }
        if (query == "cnt") {
            if (find(root, x) != NULL) {
                cout << duplicate[x] << endl;
            } else {
                cout << 0 << endl;
            }
        }
        if (query == "delete") {
            if (duplicate[x] > 1) {
                duplicate[x]--;
            } else if (duplicate[x] == 1) {
                root = deleteNode(root, x);
                duplicate[x] = 0;
            }
        }
    }
}
