#include<bits/stdc++.h>
using namespace std;
int main()
{
    int bin;
    cin >> bin;
    int deci = 0;
    for (int i = 0; bin; i++)
    {
        int last_digit = bin % 10;
        deci = last_digit * pow(2, i) + deci;
        bin = bin / 10;
    }
    cout << deci;
}