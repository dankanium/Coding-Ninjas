#include <bits/stdc++.h>
using namespace std;
void print(int **edges, int v, int sv, bool *visited) {
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        cout << front << endl;
        for (int i = 0; i < v; i++) {
            if (edges[front][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
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

    for(int i=0;i<v;i++){  // For disconnected graphs
        if(visited[i]==0){   // If any node left
              print(edges, v, i, visited);
        }   
    }

    delete[] visited;
    for (int i = 0; i < v; i++) {
        delete[] edges[i];
    }
    delete[] edges;
}
