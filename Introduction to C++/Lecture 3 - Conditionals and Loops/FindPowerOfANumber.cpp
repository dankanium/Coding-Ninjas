#include <iostream>
using namespace std;
int main()
{
    int x, n;
    cin >> x >> n;
    long long int power = x;
    int i = 2;
    if (n == 0)
        power = 1;
    else if (n == 1)
        power = x;
    else
    {
        while (i <= n)
        {
            power = power * x;
            i++;
        }
    }
    cout << power;
}