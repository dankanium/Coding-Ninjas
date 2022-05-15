#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 1;
    char c = 'A' + n - 1;
    while (i <= n)
    {
        char d = c;
        int j = 1;
        while (j <= i)
        {
            cout << d;
            j++;
            d++;
        }
        cout << endl;
        c--;
        i++;
    }
}