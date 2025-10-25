#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i < n; i++){
        int bir = arr[i];

        for(int j = 2; j*j <= bir; j++){
            while(bir % j == 0){
                mp[i]++;
                bir /= i;
            }
        }

        if(bir > 1) mp[bir]++;
    }


}