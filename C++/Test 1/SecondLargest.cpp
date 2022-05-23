#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x;
    int max = INT_MIN, sec_large = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (i == 1)
        {
            max = x;
        }
        else if (max < x)
        {
            sec_large = max;
            max = x;
        }
        else if (max > x and sec_large < x)
        {
            sec_large = x;
        }
    }
    cout << sec_large;
}