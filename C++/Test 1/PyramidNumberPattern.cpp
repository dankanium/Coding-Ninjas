#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int space = 1; space <= n - i; space++)
        {
            cout << " ";
        }
        for (int j = i, count = 1; count <= 2 * i - 1; count++)
        {
            if (count <= i)
            {
                cout << j;
                j--;
                if (count == i)
                    j++;
            }
            else
            {
                j++;
                cout << j;
            }
        }
        cout << endl;
    }
}