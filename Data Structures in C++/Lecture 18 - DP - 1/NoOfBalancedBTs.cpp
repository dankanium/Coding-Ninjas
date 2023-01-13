#include <iostream>
using namespace std;
#include <cmath>
// Brute recursive, slowest
int balancedBTs(int n) {
    if (n <= 1) {
        return 1;
    }
    int mod = (int)(pow(10, 9) + 7);
    int x = balancedBTs(n - 1);
    int y = balancedBTs(n - 2);
    int temp1 = (int)(((long)(x) * x) % mod);
    int temp2 = (int)((2 * (long)(x) * y) % mod);
    int ans = (temp1 + temp2) % mod;
    return ans;
}
// Memoization solution, average
int helper(int n, int *ans) {
    if (n <= 1) {
        return 1;
    }
    if (ans[n] != -1) {
        return ans[n];
    }
    int mod = (int)(pow(10, 9) + 7);
    int x = helper(n - 1, ans);
    int y = helper(n - 2, ans);
    int temp1 = (int)(((long)(x) * x) % mod);
    int temp2 = (int)((2 * (long)(x) * y) % mod);
    int count = (temp1 + temp2) % mod;
    ans[n] = count;
    return ans[n];
}
int balancedBTs(int n) {
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
        ans[i] = -1;
    return helper(n, ans);
}
// DP solution, fastest
int balancedBTs(int n) {
    int *ans = new int[n + 1];
    ans[0] = 1;
    ans[1] = 1;
    int mod = (int)(pow(10, 9) + 7);
    for (int i = 2; i <= n; i++) {
        int x = ans[i - 1];
        int y = ans[i - 2];
        int temp1 = (int)(((long)(x) * x) % mod);
        int temp2 = (int)((2 * (long)(x) * y) % mod);
        int count = (temp1 + temp2) % mod;
        ans[i] = count;
    }
    return ans[n];
}
int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}