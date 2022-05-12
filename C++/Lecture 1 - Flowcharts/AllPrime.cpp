#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int j = 2; j <= i - 1; j++)
        {
            if (i%j == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
            cout << i << " ";
    }
    return 0;
}