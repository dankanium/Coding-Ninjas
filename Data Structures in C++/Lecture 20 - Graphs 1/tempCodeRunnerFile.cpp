#include<bits/stdc++.h>
using namespace std;
void getComponents(int **edges, int v, int start, bool *visited, vector<int> ans) {
    visited[start] = true;
    ans.push_back(start);
    for (int i = 0; i < v; i++) {
        if (i == start)
            continue;
        if (edges[start][i] == 1 && !visited[i]) {
            getComponents(edges, v, i, visited, ans);
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

    vector<vector<int>> ans;
    int k = 0;
    for (int i = 0; i < v; i++) {
        if (!visited[i])
            getComponents(edges, v, i, visited, ans[k++]);
    }

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    delete[] visited;
    for (int i = 0; i < v; i++)
        delete[] edges[i];
    delete[] edges;
    return 0;
}