#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 1;
    for (;; i++)
    {
        if (i*i < n)
            continue;
        else 
        {
            i--;
            break;
        }
    }
    cout << i;
}