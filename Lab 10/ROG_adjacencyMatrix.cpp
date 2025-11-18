/*
A Graph is a non-linear data structure consisting of vertices and edges.
The vertices are sometimes also referred to as nodes and the edges are lines or arcs that connect any two nodes in the graph.
More formally a Graph is composed of a set of vertices(V) and a set of edges(E).
The graph is denoted by G(V, E).

2 simple ways of representing the graph:
1. Adjacency Matrix
2. Adjacency List

*/




#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> createUndirectedGraph(int V, vector<vector<int>> &edges){
    vector<vector<int>> mat(V, vector<int>(V, 0));

    for(auto &it : edges){
        int u = it[0];
        int v = it[1];
        mat[u][v] = 1;

        // since the graph is undirected
        mat[v][u] = 1; 
    }

    return mat;
}


vector<vector<int>> createDirectedGraph(int V, vector<vector<int>> &edges) {
    vector<vector<int>> mat(V, vector<int>(V, 0));

    // Add each edge to the adjacency matrix
    for (auto &it : edges) {
        int u = it[0];
        int v = it[1];
        mat[u][v] = 1;
       
    }
    return mat;
}


int main(){
    int V = 3;
    vector<vector<int>> edges = {{0,1}, {0,2}, {1,2}};
    vector<vector<int>> mat = createUndirectedGraph(V, edges);


    cout << "Adjacency Matrix Representation:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    /*
    Adjacency Matrix Representation:
    0 1 1 
    1 0 1 
    1 1 0 
    */


    vector<vector<int>> directedEdges = {{1, 0},{2, 0},{1, 2}};
    vector<vector<int>> mat = createDirectedGraph(V, directedEdges);
    cout << "Adjacency Matrix Representation:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    /*
    Adjacency Matrix Representation:
        0 0 0 
        1 0 1 
        1 0 0 
    */


    return 0;
}