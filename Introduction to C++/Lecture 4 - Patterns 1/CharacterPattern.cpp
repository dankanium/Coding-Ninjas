#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 1;
    char c = 'A';
    while (i <= n)
    {
        char d = c;
        int j = i;
        while (j)
        {
            cout << d;
            j--;
            d++;
        }
        cout << endl;
        i++;
        c++;
    }
}