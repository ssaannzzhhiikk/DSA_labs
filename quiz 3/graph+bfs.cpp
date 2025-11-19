#include <bits/stdc++.h>
using namespace std;
/*
Характеристика	Adjacency Matrix	Adjacency List
Хранение	    n x n матрица	    n списков смежности
Память	           O(n²)	            O(n + m)
Перебор соседей	   O(n)	               O(число соседей)
Удобно для плотных графов	Да	        Нет
Удобно для разреженных графов	Нет  	Да
*/
void BFS_Matrix(const vector<vector<int>> &adjMatrix, int start) {
    int n = adjMatrix.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";

        for(int v = 0; v < n; v++) {
            if(adjMatrix[u][v] && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}



void BFS_List(const vector<vector<int>> &adjList, int start) {
    int n = adjList.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";

        for(int v : adjList[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}


vector<int> BFS_ShortestPath(const vector<vector<int>> &adjList, int start) {
    int n = adjList.size();
    vector<int> distance(n, -1); // -1 = не достигнута
    queue<int> q;

    distance[start] = 0; // расстояние до стартовой = 0
    q.push(start);

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(int v : adjList[u]) {
            if(distance[v] == -1) { // не посещена
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }

    return distance; // расстояние от start до всех вершин
}

int main() {
    int n = 6;
    vector<vector<int>> adjList(n);

    // пример графа
    adjList[0] = {1, 2};
    adjList[1] = {0, 3};
    adjList[2] = {0, 4};
    adjList[3] = {1};
    adjList[4] = {2,5};
    adjList[5] = {4};

    vector<int> dist = BFS_ShortestPath(adjList, 0);

    for(int i=0; i<n; i++)
        cout << "Distance from 0 to " << i << " = " << dist[i] << "\n";
}