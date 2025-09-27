#include <bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> &arr, int x){
    int l = 0, r = arr.size();

    while(l < r){
        int mid = (r + l) / 2;

        if(arr[mid] < x) l = mid + 1;

        else r = mid;
        
    }
    return l;
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> blocks(N);
    for(int i = 0 ; i < N; i++){
        cin >> blocks[i];
    }

    for(int i = 1; i < N; i++){
        blocks[i] += blocks[i-1];
    }


    for(int i = 0; i < M; i++){
        int x;
        cin >> x;
        cout << lower_bound(blocks, x) + 1 << endl;
    }

}