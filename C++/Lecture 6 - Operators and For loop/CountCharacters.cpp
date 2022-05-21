#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    int char_count = 0, space_count = 0, digit_count = 0;
    while (c != '$')
    {
        c = cin.get();
        cout << c;
        if (97 <= c and c <= 122)
            char_count++;
        else if (48 <= c and c <= 57)
            digit_count++;
        else if (c == ' ' or c == '\t' or c == '\n')
            space_count++;
    }
    cout << char_count << " " << digit_count << " " << space_count;
}