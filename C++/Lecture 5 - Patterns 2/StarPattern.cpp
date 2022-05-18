#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= n-i)
        {
            cout << " ";
            j++;
        }
        int count = 1;
        while (count <= 2 * i - 1)
        {
            cout << "*";
            count++;
        }
        cout << endl;
        i++;
    }
}