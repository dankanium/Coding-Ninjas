#include<bits/stdc++.h>
using namespace std;
bool hasPath(int **edges, int v, bool *visited, int start, int end) {
    visited[start] = true;
    if (edges[start][end] == 1) {
        return true;
    }
    for (int i = 0; i < v; i++) {
        if (i == start) {
            continue;
        }
        if (edges[start][i] == 1 && !visited[i]) {
            if (hasPath(edges, v, visited, i, end)) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    int v, e;
    cin >> v >> e;
    int **edges = new int *[v];
    for (int i = 0; i < v; i++) {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++)
            edges[i][j] = 0;
    }

    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }

    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;

    int start, end;
    cin >> start >> end;

    bool ans = hasPath(edges, v,  visited, start, end);
    if (ans)
        cout << "true";
    cout << "false";

    for (int i = 0; i < v; i++) {
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}