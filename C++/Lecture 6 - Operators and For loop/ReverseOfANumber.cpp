#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int reverse = 0;
    while (n)
    {
        int last_digit = n % 10;
        reverse = reverse * 10 + last_digit;
        n = n / 10;
    }
    cout << reverse;
}