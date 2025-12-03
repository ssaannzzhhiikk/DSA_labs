#include <bits/stdc++.h>
using namespace std;
#define pu push_back
#define mp make_pair
#define f first
#define s second

vector<pair<int, pair<int, int>>> g;
int n, m, x, y, l;
int r[100];
int p[100];

int find(int v){
    if(p[v] == v)
        return v;
    p[v] = find(p[v]);
    return p[v];
}

void union_set(int v, int u){
    v = find(v);
    u = find(u);

    if(r[u] > r[v]){
        p[v] = u;
    } else if(r[u] < r[v]){
        p[u] = v;
    } else{
        p[u] = v;
        r[v]++;
    }
}



int main(){
    cin >> n >> m; // n — количество вершин в графе | m — количество рёбер в графе

    for(int i = 0; i < m; i++){
        cin >> x >> y >> l;
        x--;y--;
        g.push_back(mp(l, mp(x, y)));  // l - длина  x,y - вершины ребра
    }

    sort(g.begin(), g.end());

    for(int i = 0; i < n; i++){
        p[i] = i;
    }

    for(int i = 0; i < m; i++){
        x = g[i].s.f;
        y = g[i].s.s;

        if(find(x) != find(y)){
            cout << x+1 << " A " << y+1 << endl;
            union_set(x, y);
        }
    }
    return 0;

}

/*
5 6 2
2 A 3
5 A 6
4 A 5
1 A 2
2 A 4

*/