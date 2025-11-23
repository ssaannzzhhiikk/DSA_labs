#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    vector<long long> path;
    long long cur = b;

    while(cur > a) {
        path.push_back(cur);
        if(cur % 2 == 0)
            cur /= 2;
        else
            cur += 1;
    }
    
    while(cur < a) { // если a > cur после делений
        path.push_back(cur);
        cur++;
    }
    path.push_back(a);

    reverse(path.begin(), path.end());

    cout << path.size() - 1 << endl; // количество операций
    for(size_t i = 1; i < path.size(); i++)
        cout << path[i] << " ";
    cout << endl;

    return 0;
}
