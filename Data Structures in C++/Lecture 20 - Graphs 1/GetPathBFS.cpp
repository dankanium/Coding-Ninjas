#include<bits/stdc++.h>
using namespace std;
int getPathBFS(int **edges, int v, int start, int end, bool *visited, unordered_map<int, int> ans) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    ans[start] = -1;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (int i = 0; i < v; i++) {
            if (edges[front][i] == 1 && !visited[i]) {
                ans[i] = front;
                q.push(i);
                visited[i] = true;
                if (i == end)
                    return 0;   
            }
        }
    }
    return -1;
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

    unordered_map<int, int> ans;
    int c = getPathBFS(edges, v, start, end, visited, ans);
    if (c == -1)
        return 0;
    for (int i = end; i != -1;) {
        cout << i << " ";
        i = ans[i];
    }
    cout << start;
    delete[] visited;
    for (int i = 0; i < v; i++)
        delete[] edges[i];
    delete[] edges;
    return 0;
}