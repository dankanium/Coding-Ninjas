#include <iostream>
using namespace std;

int longestIncreasingSubsequence(int* arr, int n) {
    int *dp = new int[n + 1];
    dp[0] = 0;  // since n = 0, no subsequence
    dp[1] = 1;  // n = 1, only 1 element
    for (int i = 2; i <= n; i++) {
        int current = arr[i - 1];
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (current > arr[j - 1]) {
                if (dp[i] <= dp[j]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (ans < dp[i])
            ans = dp[i];
    }
    delete[] dp;
    return ans;
}
int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}