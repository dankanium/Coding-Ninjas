#include <bits/stdc++.h>
#include <vector>
using namespace std;
string str = "CODINGNINJAS";
pair<int, int> hasChar(vector<vector<char>> &board, int n, int m, int i, int j, int charIndex, vector<vector<bool>> &visited)
{
    if (i - 1 >= 0 && j - 1 >= 0 and board[i - 1][j - 1] == str[charIndex] and !visited[i - 1][j - 1])
    {
        return {i - 1, j - 1};
    }
    else if (i - 1 >= 0 and board[i - 1][j] == str[charIndex] and !visited[i - 1][j])
    {
        return {i - 1, j};
    }
    else if (i - 1 >= 0 and j + 1 < m and board[i - 1][j + 1] == str[charIndex] and !visited[i - 1][j + 1])
    {
        return {i - 1, j + 1};
    }
    else if (j - 1 >= 0 and board[i][j - 1] == str[charIndex] and !visited[i][j - 1])
    {
        return {i, j - 1};
    }
    else if (j + 1 < m and board[i][j + 1] == str[charIndex] and !visited[i][j + 1])
    {
        return {i, j + 1};
    }
    else if (i + 1 < n and j - 1 >= 0 and board[i + 1][j - 1] == str[charIndex] and !visited[i + 1][j - 1])
    {
        return {i + 1, j - 1};
    }
    else if (i + 1 < n and board[i + 1][j] == str[charIndex] and !visited[i + 1][j])
    {
        return {i + 1, j};
    }
    else if (i + 1 < n and j + 1 < m and board[i + 1][j + 1] == str[charIndex] and !visited[i + 1][j + 1])
    {
        return {i + 1, j + 1};
    }
    else
        return {-1, -1};
}
bool hasPath(vector<vector<char>> &board, int n, int m, vector<vector<bool>> &visited, int charIndex, int i, int j)
{
    visited[i][j] = true;
    if (charIndex == 11)
        return true;
    if (hasChar(board, n, m, i, j, charIndex + 1, visited).first != -1)
    {
        pair<int, int> a = hasChar(board, n, m, i, j, charIndex + 1, visited);
        return hasPath(board, n, m, visited, charIndex + 1, a.first, a.second);
    }
    visited[i][j] = false;
    return false;
}
bool hasPath(vector<vector<char>> &board, int n, int m)
{
    vector<vector<bool>> visited(n, vector<bool>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'C')
            {
                if (hasPath(board, n, m, visited, 0, i, j))
                    return true;
            }
        }
    }
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);
}
#include <bits/stdc++.h>
bool bfs(vector<vector<char>> &board, int n, int m, int ci, int cj, vector<vector<bool>> &visited, string s)
{
    if (s.size() == 0)
    {
        return true;
    }
    visited[ci][cj] = true;

    bool ans = false;
    if (ci + 1 < n && !visited[ci + 1][cj] && board[ci + 1][cj] == s[0]) // down
    {
        if (bfs(board, n, m, ci + 1, cj, visited, s.substr(1)))
            return true;
    }

    if (ci - 1 >= 0 && !visited[ci - 1][cj] && board[ci - 1][cj] == s[0]) // up

    {
        if (bfs(board, n, m, ci - 1, cj, visited, s.substr(1)))
            return true;
    }
    if (cj - 1 >= 0 && !visited[ci][cj - 1] && board[ci][cj - 1] == s[0]) // left
    {
        if (bfs(board, n, m, ci, cj - 1, visited, s.substr(1)))
            return true;
    }

    if (cj + 1 < m && !visited[ci][cj + 1] && board[ci][cj + 1] == s[0]) // right
    {
        if (bfs(board, n, m, ci, cj + 1, visited, s.substr(1)))
            return true;
    }

    if (ci + 1 < n && cj - 1 >= 0 && !visited[ci + 1][cj - 1] && board[ci + 1][cj - 1] == s[0]) // down left
    {
        if (bfs(board, n, m, ci + 1, cj - 1, visited, s.substr(1)))
            return true;
    }

    if (ci + 1 < n && cj + 1 < m && !visited[ci + 1][cj + 1] && board[ci + 1][cj + 1] == s[0]) // down right
    {
        if (bfs(board, n, m, ci + 1, cj + 1, visited, s.substr(1)))
            return true;
    }

    if (ci - 1 >= 0 && cj - 1 >= 0 && !visited[ci - 1][cj - 1] && board[ci - 1][cj - 1] == s[0]) // up left
    {
        if (bfs(board, n, m, ci - 1, cj - 1, visited, s.substr(1)))
            return true;
    }

    if (ci - 1 >= 0 && cj + 1 < m && !visited[ci - 1][cj + 1] && board[ci - 1][cj + 1] == s[0]) // up right
    {
        if (bfs(board, n, m, ci - 1, cj + 1, visited, s.substr(1)))
            return true;
    }

    visited[ci][cj] = false;

    return ans;
}

bool hasPath(vector<vector<char>> &board, int n, int m)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'C')
            {

                string s = "ODINGNINJA";

                if (bfs(board, n, m, i, j, visited, s))
                    return true;
            }
        }
    }
    return false;
}
