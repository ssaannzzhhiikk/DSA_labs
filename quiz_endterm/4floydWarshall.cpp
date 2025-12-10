#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void floydWarshall(vector<vector<int>> &dist) {
    int V = dist.size();
    const int INF = 1e8;

    // Теперь порядок циклов i → j → k
    for (int i = 0; i < V; i++) {             // фиксируем источник
        for (int j = 0; j < V; j++) {         // фиксируем получателя
            for (int k = 0; k < V; k++) {     // пробуем разные промежуточные вершины

                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    const int INF = 100000000;
    vector<vector<int>> dist = {
        {0, 4, INF, 5, INF},
        {INF, 0, 1, INF, 6},
        {2, INF, 0, 3, INF},
        {INF, INF, 1, 0, 2},
        {1, INF, INF, 4, 0}
    };

    floydWarshall(dist);

    for (int i = 0; i < dist.size(); i++) {
        for (int j = 0; j < dist.size(); j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
