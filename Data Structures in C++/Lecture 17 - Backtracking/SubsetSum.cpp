#include<bits/stdc++.h>
using namespace std;
int subsetSum(int *arr, int n, int sum) {
    if (n == 0) {
        if (sum >= 0) {
        	return 1;
    	}
        return 0;
    }
    int ans = 0;
    ans += subsetSum(arr + 1, n - 1, sum - arr[0]);
    ans += subsetSum(arr + 1, n - 1, sum);
    return ans;
}
int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int t;
    cin >> t;
    while (t--) {
        int c;
        cin >> c;
        cout << subsetSum(arr, n, c) << endl;
    }
    return 0;
}