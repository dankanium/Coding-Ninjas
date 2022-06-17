#include <iostream>
#include <cstring>
using namespace std;

#include <climits>

char highestOccurringChar(char input[]) {
    int freq[256] = {0};
    for (int i = 0; input[i] != '\0'; i++)
    {
        freq[input[i]]++;
    }
    int max = INT_MIN;
    for (int i = 0; i < 256; i++)
    {
        if (freq[i] > max)
            max = freq[i];
    }
    for (int i = 0; i < 256; i++)
    {
        if (max == freq[i])
            return i;
    }
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << highestOccurringChar(str);
}