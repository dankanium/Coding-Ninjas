#include<bits/stdc++.h>
using namespace std;
int countStepsToOne(int n) {
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 0;
    ans[2] = 1;
    ans[3] = 1;
    for (int i = 4; i <= n; i++) {
        if (i % 2 == 0) {
            ans[i] = ans[i / 2] + 1;
        }
        else if (i % 3 == 0) {
            ans[i] = ans[i / 3] + 1;
        }
        else 
            ans[i] = ans[i - 1] + 1;
    }
    return ans[n];
}
int main() {
    int n;
    cin >> n;
    cout << countStepsToOne(n);
}