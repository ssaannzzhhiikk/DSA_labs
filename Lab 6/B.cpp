#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, x;
    map<int, int> altynai;
    vector<int> amina;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> x;
        altynai[x]++;
    }

    for(int i = 0; i < m; i++){
        cin >> x;
        if(altynai[x]){
            amina.push_back(x);
            altynai[x]--;
        }
    }

    sort(amina.begin(), amina.end());

    for(int x : amina){
        cout << x << " ";
    }

    return 0;
}