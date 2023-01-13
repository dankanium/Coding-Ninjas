#include<bits/stdc++.h>
using namespace std;
void isConnected(int **edges, int v, bool *visited, int start) {
    visited[start] = true;
    for (int i = 0; i < v; i++) {
        if (i == start)
            continue;
        if (edges[start][i] == 1) {
            if (visited[i])
                continue;
            isConnected(edges, v, visited, i);
        }
    }
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

    isConnected(edges, v, visited, 0);
    bool flag = false;
    for (int i = 0; i < v; i++) {
        if (visited[i] == false) {
            flag = true;
            cout << "false";
            break;
        }
    }
    if (flag == false)
        cout << "true";
    delete[] visited;
    for (int i = 0; i < v; i++)
        delete[] edges[i];
    delete[] edges;
    return 0;
}