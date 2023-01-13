#include <iostream>
using namespace std;

int knapsack(int *weights, int *values, int n, int maxWeight) {
    if (maxWeight <= 0 or n <= 0) {
        return 0;
    }
    if (weights[0] > maxWeight) {
        return knapsack(weights + 1, values + 1, n - 1, maxWeight);
    }
    int a = knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]) + values[0];
    int b = knapsack(weights + 1, values + 1, n - 1, maxWeight);
    return max(a, b);
}
// Memoization
int helper(int *weights, int *values, int n, int maxWeight, int **memo) {
	if (maxWeight <= 0 or n <= 0) {
        return 0;
    }
	if (memo[n][maxWeight] != -1) {
		return memo[n][maxWeight];
	}
    if (weights[0] > maxWeight) {
        return helper(weights + 1, values + 1, n - 1, maxWeight, memo);
    }
    int a = helper(weights + 1, values + 1, n - 1, maxWeight - weights[0], memo) + values[0];
    int b = helper(weights + 1, values + 1, n - 1, maxWeight, memo);
    memo[n][maxWeight] = max(a, b);
	return memo[n][maxWeight];
}
int knapsack(int *weights, int *values, int n, int maxWeight) {
	int **memo = new int *[n + 1];
	for (int i = 0; i <= n; i++) {
		memo[i] = new int[maxWeight + 1];
		for (int j = 0; j <= maxWeight; j++) {
			memo[i][j] = -1;
		}
	}
	int ans = helper(weights, values, n, maxWeight, memo);
	for (int i = 0; i <= n; i++) {
		delete[] memo[i];
	}
	delete[] memo;
	return ans;
}
// DP
int knapsack(int *weights, int *values, int n, int maxWeight) {
	int **dp = new int *[n + 1];
	for (int i = 0; i <= n; i++) {
		dp[i] = new int[maxWeight + 1];
	}
	
}
int main()
{
	int n;
	cin >> n;

	int *weights = new int[n];
	int *values = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weights, values, n, maxWeight) << endl;

	delete[] weights;
	delete[] values;
}