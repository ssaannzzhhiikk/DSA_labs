#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> primes;
    vector<int> super;
    int num = 2;
    while(super.size() < n){
        if(isPrime(num)){
            primes.push_back(num);
            if(isPrime(primes.size())){
            super.push_back(num);
            }
        }
        num++;
    }
    cout << super[n-1];
}
