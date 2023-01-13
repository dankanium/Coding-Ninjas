#include <bits/stdc++.h>
using namespace std;
int count(int denominations[], int numDenominations, int value){
    if (value == 0) {
        return 1;
    }
    if (value < 0 or numDenominations <= 0) {
        return 0;
    }
    if (denominations[0] > value) {
        return count(denominations + 1, numDenominations - 1, value);
    }
    int a = count(denominations, numDenominations, value - denominations[0]);
    int b = count(denominations + 1, numDenominations - 1, value);
    return a + b;
}
int helper(int denominations[], int numDenominations, int value, int **memo){
    if (value == 0) {
        return 1;
    }
    if (value < 0 or numDenominations <= 0) {
        return 0;
    }
    if (denominations[0] > value) {
        return helper(denominations + 1, numDenominations - 1, value, memo);
    }
    if (memo[numDenominations][value] != -1) {
        return memo[numDenominations][value];
    }
    int a = helper(denominations, numDenominations, value - denominations[0], memo);
    int b = helper(denominations + 1, numDenominations - 1, value, memo);
    memo[numDenominations][value] = a + b;
    return memo[numDenominations][value];
}
int countWaysToMakeChange(int denominations[], int numDenominations, int value){
    int **memo = new int *[numDenominations + 1];
    for (int i = 0; i <= numDenominations; i++) {
        memo[i] = new int[value + 1];
        for (int j = 0; j <= value; j++) {
            memo[i][j] = -1;
        }
    }
    int ans = helper(denominations, numDenominations, value, memo);
    for (int i = 0; i <= numDenominations; i++) {
        delete[] memo[i];
    }
    delete[] memo;
    return ans;
}
int main()
{

	int numDenominations;
	cin >> numDenominations;
	
	int *denominations = new int[numDenominations];

	for (int i = 0; i < numDenominations; i++)
	{
		cin >> denominations[i];
	}

	int value;
	cin >> value;

	cout << countWaysToMakeChange(denominations, numDenominations, value);

	delete[] denominations;
}