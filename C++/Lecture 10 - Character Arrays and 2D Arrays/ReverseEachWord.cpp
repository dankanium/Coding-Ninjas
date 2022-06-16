#include <iostream>
#include <cstring>
using namespace std;

void reverseWord(char input[], int s, int e)
{
    for (int i = s, j = e; i <= j; i++, j--)
    {
        char temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
}
void reverseEachWord(char input[]) {
    // Write your code here
    int i = 0, j = 1;
    while (j <= strlen(input))
    {
        if (input[j] == ' ' or input[j] == '\0')
        {
            reverseWord(input, i, --j);
            i = j + 2;
            j = i + 1;
        }
        else {
            j++;
        }
    }
}

int main() {
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    reverseEachWord(str);
    cout << str;
}