#include <bits/stdc++.h>
using namespace std;

// O(sqrt(N))
void primeFactors(int n){
    for(int i = 2; i*i <= n; i++){
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
}
