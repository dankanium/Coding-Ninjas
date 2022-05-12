#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    while (n >= 2)
    {
        if (n%2 == 0)
        {
            sum = sum + n;
        }
        n--;
    }
    cout << sum;
}