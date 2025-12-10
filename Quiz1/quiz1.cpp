#include <bits/stdc++.h>
using namespace std;


// Eratosthene Sieve
vector<int> sieve(int n){
    vector<bool> prime(n + 1, true);
    for(int i = 0; i*i<=n; i++){
        if(prime[i] == true){
            for(int j = i*i; j <= i; j+=i){
                prime[j] = false;
            }
        }
    }

    vector<int> res;
    for(int p = 2; p <= n; p++){
        if(prime[p]){
            res.push_back(p);
        }
    }

    return res;
}

// GCD
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}


// Reverse Linked List
struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL){}
};

Node* reverse(Node* head){
    Node* cur = head;
    Node* next = NULL;
    Node* prev = NULL;

    while(cur != NULL){
        next = cur->next;
        cur->next = prev;

        prev = cur;
        cur = next;
    }

    return prev;
}

void insert(Node *head, Node* tail, int x){
    Node* newNode = new Node(x);
    if(!head) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

// Binary Search
int binarySearch(vector<int> arr, int target){
    int low = 0;
    int high = arr.size() - 1;

    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == target){
            return mid;
        } else if(arr[mid] < target){
            low = mid + 1;
        } else{
            high = mid - 1; 
        }
    }
    return -1;
}


int main(){

}