#include <bits/stdc++.h>
using namespace std;
// Brute force recursive
int minCostPath(int **input, int m, int n, int i, int j) {
	if (i == m - 1 and j == n - 1)
		return input[i][j];
	if (i >= m or j >= n)
		return INT_MAX;
	int x = minCostPath(input, m, n, i + 1, j);
	int y = minCostPath(input, m, n, i, j + 1);
	int z = minCostPath(input, m, n, i + 1, j + 1);
	return min(x, min(y, z)) + input[i][j];
}
int minCostPath(int **input, int m, int n)
{
	minCostPath(input, m, n, 0, 0);
}
// Memoization
int helper(int **input, int m, int n, int i, int j, int **ans) {
    if (i == m - 1 and j == n - 1) {
        return input[i][j];
    }
    if (i >= m or j >= n) {
        return INT_MAX;
    }
    if (ans[i][j] != -1) {
        return ans[i][j];
    }
    int x = helper(input, m, n, i + 1, j, ans);
	int y = helper(input, m, n, i, j + 1, ans);
	int z = helper(input, m, n, i + 1, j + 1, ans);
	ans[i][j] = min(x, min(y, z)) + input[i][j];
    return ans[i][j];
}
int minCostPath(int **input, int m, int n) {
    int **ans = new int *[m + 1];
    for (int i = 0; i <= m; i++) {
        ans[i] = new int[n + 1];
        for (int j = 0; j <= n; j++) {
            ans[i][j] = -1;
        }
    }
    return helper(input, m, n, 0, 0, ans);
}
// DP
int minCostPath(int **input, int m, int n) {
    int **ans = new int *[m];
    for (int i = 0; i <= m; i++) {
        ans[i] = new int[n];
    }
    ans[m - 1][n - 1] = input[m - 1][n - 1];
    // last row, right to left
    for (int i = n - 2; i >= 0; i--) {
        ans[m - 1][i] = ans[m - 1][i + 1] + input[m - 1][i];
    }
    // last column, bottom to up
    for (int i = m - 2; i >= 0; i--) {
        ans[i][n - 1] = ans[i + 1][n - 1] + input[i][n - 1];
    }
    for (int i = m - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            int x = ans[i + 1][j + 1];
            int y = ans[i + 1][j];
            int z = ans[i][j + 1];
            ans[i][j] = min(x, min(y, z)) + input[i][j];
        }
    }
    return ans[0][0];
}
int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
}