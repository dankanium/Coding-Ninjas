#include <iostream>
using namespace std;

int maxMoneyLooted(int *arr, int n)
{
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = arr[0];
    for (int i = 2; i <= n; i++) {
        dp[i] = max(arr[i - 1] + dp[i - 2], dp[i - 1]);
    }
    return dp[n];
}
int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}