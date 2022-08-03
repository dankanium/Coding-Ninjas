#include <iostream>
#include <string.h>
using namespace std;
int getCodes(string input, string output[10000])
{
    if (input[0] == '\0')
        return 0;
    string o1[10000], o2[10000];
    int x, y, i = 0;
    char sub1 = input[0], sub2 = input[1];
    if (1 <= sub1 - '0' <= 10)
    {
        x = getCodes(input.substr(1), o1);
        char c = 'a' + sub1 - '0' - 1;
        for (int k = 0; k < x; k++)
        {
            output[i++] = c + o1[k];
        }
    }
    if ((sub1 - '0' == 1 and 1 <= sub2 - '0' <= 9) or (sub1 - '0' == 2 and 0 <= sub2 - '0' <= 6))
    {
        y = getCodes(input.substr(2), o2);
        char c;
        if (sub1 == 1)
            c = 'a' + 10 + sub2 - '0' - 1;
        else if (sub2 == 2)
            c = 'a' + 20 + sub2 - '0' - 1;
        for (int j = 0; j < y; j++)
        {
            output[i++] = c + o2[j];
        }
    }
    return i - 1;
}
int main()
{
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for (int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
