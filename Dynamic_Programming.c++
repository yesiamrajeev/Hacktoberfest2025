Dynamic Programming idea:

Let dist[i][j] = shortest distance from vertex i to vertex j using only vertices 1..k as intermediate nodes.

Recurrence relation:

dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])



---

C++ Implementation

#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9; // Represents infinity

void floydWarshall(int n, vector<vector<int>>& graph) {
    vector<vector<int>> dist = graph; // Copy initial graph

    // Dynamic Programming steps
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) // Avoid overflow
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Print shortest distance matrix
    cout << "Shortest distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter adjacency matrix (use 1e9 for INF):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    floydWarshall(n, graph);

    return 0;
}

