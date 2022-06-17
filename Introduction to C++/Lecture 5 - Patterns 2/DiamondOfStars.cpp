#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 1;
    int middle = (n + 1) / 2;
    int stars = 1;
    int spaces = n / 2;
    while (i <= middle)
    {
        int space_count = 1;
        while (space_count <= spaces)
        {
            cout << " ";
            space_count++;
        }
        int count = 1;
        while (count <= stars)
        {
            cout << "*";
            count++;
        }
        cout << endl;
        i++;
        stars += 2;
        spaces--;
    }
    stars = n - 2;
    spaces = 1;
    while (i <= n)
    {
        int space_count = 1;
        while (space_count <= spaces)
        {
            cout << " ";
            space_count++;
        }
        int count = 1;
        while (count <= stars)
        {
            cout << "*";
            count++;
        }
        cout << endl;
        i++;
        stars -= 2;
        spaces++;
    }
}
// --*
// -***
// *****
// -***
// --*   
 