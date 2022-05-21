#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    for (int n = 1; x != 0; n++)
    {
        int term = 3 * n + 2;
        if (term % 4 != 0)
        {
            cout << term << " ";
            x--;
        }
    }
}