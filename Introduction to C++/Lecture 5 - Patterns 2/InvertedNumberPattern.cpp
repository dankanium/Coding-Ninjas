#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = n;
    while (i)
    {
        int j = i;
        while (j)
        {
            cout << i;
            j--;
        }
        cout << endl;
        i--;
    }
}