#include <iostream>
#include <cstring>
using namespace std;

void removeConsecutiveDuplicates(char input[]) {
    int pos = 1, pointer = 1;
    char lastChar = input[0];
    int len = strlen(input);
    while (pointer < len)
    {
        if (input[pointer] == lastChar)
        	pointer++;
        else
        {
            input[pos] = input[pointer];
            lastChar = input[pointer];
            pos++;
            pointer++;
        }
    }
    input[pos] = '\0';
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str;
}