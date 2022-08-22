#include <bits/stdc++.h>
using namespace std;
int maximumProfit(int budget[], int n) {
    sort(budget, budget + n);
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int temp = budget[i] * (n - i);
        if (temp > max)
            max = temp;
    }
    return max;
}
int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];
    
    cout << maximumProfit(input, n) << endl;
    
}
