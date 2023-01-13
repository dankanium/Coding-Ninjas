#include <iostream>
using namespace std;

int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
    int **dp = new int *[n];
    for (int i = 0; i < n; i ++) {
        dp[i] = new int[m];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i][0] == 0) {
            dp[i][0] = 1;
            ans = 1;
        }
        else
            dp[i][0] = 0;
    }
    for (int j = 0; j < m; j++) {
        if (arr[0][j] == 0) {
            dp[0][j] = 1;
            ans = 1;
        }
        else 
            dp[0][j] = 0;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][j] == 0) {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                if (dp[i][j] > ans)
                    ans = dp[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    return ans;
}
int main()
{
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

	delete[] arr;

	return 0;
}