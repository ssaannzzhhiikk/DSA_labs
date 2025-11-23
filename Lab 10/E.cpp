#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n, vector<int>(n));
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> adj[i][j];
    
    while(q--) {
        vector<int> elems;
        int x;
        string line;
        getline(cin >> ws, line); // считываем всю строку
        stringstream ss(line);
        while(ss >> x) elems.push_back(x-1); // переводим в 0-индексацию
        
        bool ok = true;
        for(size_t i = 0; i < elems.size(); i++)
            for(size_t j = i+1; j < elems.size(); j++)
                if(adj[elems[i]][elems[j]] == 0)
                    ok = false;
        
        cout << (ok ? "YES" : "NO") << "\n";
    }
    
    return 0;
}
