#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        int space = 1;
        while (space <= n - i)
        {
            cout << " ";
            space++;
        }
        int j = 1;
        int count = i;
        while (j <= 2*i-1)
        {
            if (j <= i)
            {
                cout << count;
                if (j < i)
                    count++;
                else
                    count--;
            }
            else 
            {
                cout << count;
                count--;
            }
            j++;
        }
        cout << endl;
        i++;
    }
}