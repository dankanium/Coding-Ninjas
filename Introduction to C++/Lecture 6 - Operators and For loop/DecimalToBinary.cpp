#include <bits/stdc++.h>
using namespace std;
int main()
{
    int deci;
    cin >> deci;
    long long bin = 0;
    for (int i = 0; deci; i++)
    {
        int bit = deci % 2;
        int power = 1;
        for (int p = i; p; p--)
        {
            power = 10 * power;
        }
        bin = bit * power + bin;
        deci = deci / 2;
    }
    cout << bin;
}