#include <iostream>
#include <cstring>
using namespace std;

bool checkPalindrome(char str[]) {
    // Write your code here
    int size = 0;
    for (int i = 0; str[i] != '\0'; i++)
        size++;
    for (int i = 0, j = size - 1; i <= j; i++, j--)
    {
        if (str[i] == str[j])
            continue;
        else
        {
            return false;
			break;
        }
    }
    return true;
}


int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << (checkPalindrome(str) ? "true" : "false");
}