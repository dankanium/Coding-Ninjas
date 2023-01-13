#include<bits/stdc++.h>
using namespace std;
vector<int> getPathDFS(int **edges, int v, bool *visited, int start, int end) {
    visited[start] = true;
    if (edges[start][end]) {
        vector<int> ans;
        ans.push_back(end);
        ans.push_back(start);
        return ans;
    }
    vector<int> ans;
    for (int i = 0; i < v; i++) {
        if (i == start)
            continue;
        if (edges[start][i] == 1 and !visited[i]) {
            ans = getPathDFS(edges, v, visited, i, end);
            if (ans[0] != -1) {
                ans.push_back(start);
                return ans;
            }
        }
    }
    return {-1};
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

    vector<int> ans = getPathDFS(edges, v, visited, start, end);
    if (ans[0] == -1)
        return 0;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }   

    delete[] visited;
    for (int i = 0; i < v; i++)
        delete[] edges[i];
    delete[] edges;
    return 0;
}