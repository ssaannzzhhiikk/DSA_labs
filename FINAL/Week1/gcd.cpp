#include <bits/stdc++.h>
using namespace std;

// O(logmin(a, b))
int gcd(int a, int b){
    if(b == 0){
        return a;
    } else{
        return gcd(b, a%b);
    }
}
