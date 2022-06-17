#include <iostream>
#include <cstring>
using namespace std;

void removeAllOccurrencesOfChar(char input[], char c) {
    // Write your code here
    for (int i = 0, j = 0; j <= strlen(input); j++)
    {
        if (input[j] != c)
        {
            input[i] = input[j];
            i++;
        }
    }
}

int main() {
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    char c;
    cin >> c;
    removeAllOccurrencesOfChar(str, c);
    cout << str;
}