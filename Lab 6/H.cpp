#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<char> chars(n);
    
    for(int i = 0; i < n; i++){
        cin >> chars[i];
    }

    char letter;
    cin >> letter;

    for(char c : chars){
        if(c > letter){
            cout << c;
            return 0;
        }
    }
    cout << chars[0];
    return 0;
}
