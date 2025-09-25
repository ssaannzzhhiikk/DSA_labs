#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n) {

    vector<bool> prime(n + 1, true);
    for (int i = 2; i*i <= n; i++) {
        if (prime[i] == true) {
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
    
    vector<int> res;
    for (int p = 2; p <= n; p++){
        if (prime[p]){ 
            res.push_back(p);
        }
    }
    return res;
}

int main(){
    int n = 20;
    vector<int> res = sieve(n);
    for(int x : res){
        cout << x << ' ';
    }
    return 0;
}