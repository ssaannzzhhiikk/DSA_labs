#include <bits/stdc++.h>
using namespace std;



int main(){
    int N, P;
    cin >> N;
    vector<int> pwr(N);

    for(int i = 0; i < N; i++){
        cin >> pwr[i];
    }
    sort(pwr.begin(), pwr.end());

    cin >> P;
    for(int i = 0; i < P; i++){
        int p, sum = 0;
        cin >> p;
        auto it = upper_bound(pwr.begin(), pwr.end(), p);
        int qt = it - pwr.begin();
        for(int j = 0; j < qt; j++){
            sum += pwr[j];
        }
        cout << it - pwr.begin() << " " << sum << endl;
    }
    
}