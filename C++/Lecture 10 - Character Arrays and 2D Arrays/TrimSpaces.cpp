#include <iostream>
#include <cstring>
using namespace std;

void trimSpaces(char input[]) {
    int k = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] != 32)
        {
            input[k] = input[i];
            k++;
            continue;
        }     
    }
    input[k] = '\0';
}

int main() {
    char input[1000000];
    cin.getline(input, 1000000);
    trimSpaces(input);
    cout << input << endl;
}