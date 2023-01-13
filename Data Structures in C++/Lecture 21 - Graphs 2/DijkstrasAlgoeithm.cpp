#include<bits/stdc++.h>
using namespace std;
int findMinVertex(int *distance, bool *visited, int n) {
    int minVertex = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])) {
            minVertex = i;
        }
    }
    return minVertex;
}
void dijkstras(int **edges, int n) {
    int *distance = new int[n];
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[0] = 0;
    for (int i = 0; i < n; i++) {
        int minVertex = findMinVertex(distance, visited, n);
        visited[minVertex] = true;
        for (int j = 0; j < n; j++) {
            if (edges[minVertex][j] && !visited[j]) {
                int currentDist = distance[minVertex] + edges[minVertex][j];
                if (currentDist < distance[j]) {
                    distance[j] = currentDist;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << i << " " << distance[i] << endl;
    }
    delete[] visited;
    delete[] distance;
}
int main() {
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
            edges[i][j] = 0;
    }
    for (int i = 0; i < e; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;
        edges[a][b] = weight;
        edges[b][a] = weight;
    }
    dijkstras(edges, n);
    for (int i = 0; i < n; i++) {
        delete[] edges[i];
    }
    delete[] edges;
}