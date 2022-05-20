#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a = 1;
    int b = 1;
    int c = 0;
    for (int i = 3; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    if (n == 1 || n == 2) // for 1st and 2nd number
        cout << 1;
    else // for Nth number
        cout << c;
}