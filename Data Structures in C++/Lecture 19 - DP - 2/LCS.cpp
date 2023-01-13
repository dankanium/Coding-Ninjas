#include<bits/stdc++.h>
using namespace std;
#define str substr(1)
/*
int lcs(string s, string t) {
    if (s[0] == '\0' || t[0] == '\0') {
        return 0;
    }
    if (s[0] == t[0]) {
        return 1 + lcs(s.str, t.str);
    }
    int a = lcs(s.str, t);
    int b = lcs(s, t.str);
    int c = lcs(s.str, t.str);
    return max(a, max(b, c));
} */
// Memoization
/*
int lcsHelper(string s, string t, int **ans) {
    if (s[0] == '\0' || t[0] == '\0') {
        return 0;
    }
    int m = s.size();
    int n = t.size();
    if (ans[m][n] != -1) {
        return ans[m][n];
    }
    if (s[0] == t[0]) {
        ans[m][n] = 1 + lcsHelper(s.str, t.str, ans);
        return ans[m][n];
    }
    int a = lcsHelper(s.str, t, ans);
    int b = lcsHelper(s, t.str, ans);
    int c = lcsHelper(s.str, t.str, ans);
    ans[m][n] = max(a, max(b, c));
    return ans[n][m];
}
int lcs(string s, string t) {
    int m = s.size();
    int n = t.size();
    int **ans = new int *[m + 1];
    for (int i = 0; i <= m; i++) {
        ans[i] = new int[n + 1];
        for (int j = 0; j <= n; j++) {
            ans[i][j] = -1;
        }
    }
    int a = lcsHelper(s, t, ans);
    delete[] ans;
    return a;
}
*/
// DP
int lcs(string s, string t) {
    int m = s.size();
    int n = t.size();
    int **ans = new int *[m + 1];
    for (int i = 0; i <= m; i++) {
        ans[i] = new int[n + 1];
        ans[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        ans[0][j] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                ans[i][j] = 1 + ans[i - 1][j - 1];
            }
            else {
                ans[i][j] = max(ans[i - 1][j - 1], max(ans[i - 1][j], ans[i][j - 1]));
            }
        }
    }
    return ans[m][n];
}
int main() {
    string s, t;
    cin >> s >> t;
    cout << lcs(s, t) << endl;
}