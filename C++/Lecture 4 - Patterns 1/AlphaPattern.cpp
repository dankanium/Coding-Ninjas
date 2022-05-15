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
        int j = i;
        while (j)
        {
            cout << c;
            j--;
        }
        cout << endl;
        i++;
        c++;
    }
}