#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 1;
    int even_sum = 0, odd_sum = 0, digit;
    while (n > 0)
    {
        digit = n % 10;
        if (digit%2 == 0)
            even_sum += digit;
        else
            odd_sum += digit;
        n = n / 10;
    }
    cout << even_sum << " " << odd_sum;
}