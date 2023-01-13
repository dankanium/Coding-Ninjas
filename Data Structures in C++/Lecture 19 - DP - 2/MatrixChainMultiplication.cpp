#include <iostream>
using namespace std;
int helper(int *arr, int start, int end, int **memo) {
    if (start == end || start == end - 1) {
        return 0;
    }
    if (memo[start][end] != -1) {
        return memo[start][end];
    }
    int minimum = 99999999;
    for (int k = start; k <= end - 1; k++) {
        int a = helper(arr, start, k, memo);
        int b = helper(arr, k, end, memo);
        int temp = a + b + (arr[start] * arr[k] * arr[end]);
        if (temp < minimum) {
            minimum = temp;
        }
    }
    memo[start][end] = minimum;
    return minimum;
}
int matrixChainMultiplication(int* arr, int n) {
    int **memo = new int *[n + 1];
    for (int i = 0; i <= n; i++) {
        memo[i] = new int[n + 1];
        for (int j = 0; j <= n; j++) {
            memo[i][j] = -1;
        }
    }
    int ans = helper(arr, 0, n, memo);
    for (int i = 0; i <= n; i++) {
        delete[] memo[i];
    }
    delete[] memo;
    return ans;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}