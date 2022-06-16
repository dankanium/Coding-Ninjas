#include <iostream>
#include <cstring>
using namespace std;

void printSubstrings(char input[]) {
    int i = 0;
    int j = i;
    for (;i < strlen(input); i++)
    {
        for (j= i; j < strlen(input); j++)
        {
            for (int k = i;k <= j; k++)
            {
                cout << input[k];
            }
            cout << endl;
        }
    }
}
int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    printSubstrings(str);
}