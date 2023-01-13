#include <iostream>
#include <string>
using namespace std;
int helper(int n, int x, int y, int *memo) {
	if (n < 1)
		return 0;
	if (n - 1 == 0 || n - x == 0 || n - y == 0)
		return 1;
	if (memo[n] != -1) {
		return memo[n];
	}
	memo[n] = helper(n - 1, x, y, memo) ^ 1 || helper(n - x, x, y, memo) ^ 1 || helper(n - y, x, y, memo) ^ 1;
	return memo[n];
}
string findWinner(int n, int x, int y)
{
	int *memo = new int[n + 1];
	for (int i = 0; i <= n; i++) {
		memo[i] = -1;
	}
	int a = helper(n, x, y, memo);
	delete[] memo;
	if (a == 1)
		return "Beerus";
	else
		return "Whis";
}
int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	cout << findWinner(n, x, y);
}