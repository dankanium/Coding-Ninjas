#include <iostream>
#include <string>
using namespace std;

int solve(string s, string v, int m, int n, int **memo) {
    if (m == 0) {
        return 99999;
    }
    if (n <= 0) {
        return 1;   
    }
    if (memo[m][n] != -1) {
        return memo[m][n];
    }
    int a = solve(s.substr(1), v, m - 1, n, memo);
    int b = 999999;
    for (int i = 0; i < v.length(); i++) {
        if (v[i] == s[0]) {
            b = solve(s.substr(1), v.substr(i + 1), m - 1, n - i, memo) + 1;
            break;
        }
    }
    if (b == 999999)
        return 1;
    memo[m][n] = min(a, b);
    return memo[m][n];
}
int solve(string s, string t) {
    int m = s.length();
    int n = t.length();
    int **memo = new int *[m + 1];
    for (int i = 0; i <= m; i++) {
        memo[i] = new int[n + 1];
        for (int j = 0; j <= n; j++) {
            memo[i][j] = -1;
        }
    }
    int ans = solve(s, t, m, n, memo);
    for (int i = 0; i <= m; i++)
        delete[] memo[i];
    delete[] memo;
    return ans;
}
int solve(string s1,string s2)
{
	int m =s1.size();
	int n =s2.size();

	vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

	for (int i = 0; i < n+1; ++i)
	{
		dp[m][i] = n-i;
	}

	for (int i = 0; i < m+1; ++i)
	{
		dp[i][n] = m-i;
	}

	for (int i = m-1; i >= 0; --i)
	{
		for (int j = n-1; j >= 0; --j)
		{
			int k = j;
			
			while(k<s2.size())
			{
				if(s2[k]==s1[i])
				{
					break;
				}
				k++;
			}
			if (k==s2.size())
			{
				dp[i][j] = 1;
				//return 1;
			}

			int c1 = 1+dp[i+1][k+1];
			int c2 = dp[i+1][j];

			dp[i][j] = min(c1, c2);
		}
	}
	return dp[0][0];
}
int main() {
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}