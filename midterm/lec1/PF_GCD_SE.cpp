#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    return (b == 0) ? a : gcd(b, a % b);
}

vector<int> primeFactors(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n); // last prime
    return factors;
}

vector<int> sieve(int n){
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i*i <= n; i++){
        if(isPrime[i]){
            for(int j = i*i; j <= n; j+=i){
                isPrime[j] = false;
            }
        }
    }


    vector<int> primes;
    for(int i = 2; i <= n; i++){
        if(isPrime[i]) primes.push_back(i);
    }

    return primes;
}

int main() {
    int a = 24, b = 18, n = 84, limit = 50;

    cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b) << "\n";
    
    cout << "Prime factors of " << n << ": ";
    vector<int> pf = primeFactors(n);
    for (int f : pf) cout << f << " ";
    cout << "\n";

    cout << "Primes up to " << limit << ": ";
    vector<int> primes = sieve(limit);
    for (int p : primes) cout << p << " ";
}