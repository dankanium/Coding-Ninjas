#include <cstring>
#include <iostream>
using namespace std;
// Brute recursion
int editDistance(string s, string t) {
    if (s.size() == 0 or t.size() == 0) {
        return max(s.size(), t.size());
    }
    int a = 999, b = 999, c = 999;
    if (s[0] == t[0]) {
        return editDistance(s.substr(1), t.substr(1));
    }
    else {
        // Insert
        a = editDistance(s.substr(1), t);
        if (t.size() != 0) {
            // Delete
            b = editDistance(s, t.substr(1));
            // Replace
            c = editDistance(s.substr(1), t.substr(1));
        }
    }
    return min(a, min(b, c)) + 1;
}
// Memoization
int helper(string s, string t, int **memo) {
    int m = s.size();
    int n = t.size();
    if (s.size() == 0 or t.size() == 0) {
        return max(s.size(), t.size());
    }
    if (memo[m][n] != -1) {
        return memo[m][n];
    }
    int a = 999, b = 999, c = 999;
    int ans;
    if (s[0] == t[0]) {
        ans = helper(s.substr(1), t.substr(1), memo);
    }
    else {
        // Insert
        a = helper(s.substr(1), t, memo);
        // Delete
        b = helper(s, t.substr(1), memo);
        // Replace
        c = helper(s.substr(1), t.substr(1), memo);
        ans = min(a, min(b, c)) + 1;
    }
    memo[m][n] = ans;
    return ans;
}
int editDistance(string s, string t) {
    int m = s.size() + 1;
    int n = t.size() + 1;
    int **memo = new int*[m];
    for (int i = 0; i <= m; i++) {
        memo[i] = new int[n];
        for (int j = 0; j <= n; j++) {
            memo[i][j] = -1;
        }
    }
    return helper(s, t, memo);
}
// DP 
int editDistance(string s, string t) {
    int m = s.size();
    int n = t.size();
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            }
            else if (j == 0) {
                dp[i][j] = i;
            }
            else {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    int a = dp[i - 1][j - 1];
                    int b = dp[i - 1][j];
                    int c = dp[i][j - 1];
                    dp[i][j] = min(a, min(b, c));
                }
            }
        }
    }
    return dp[m][n];
}
int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}