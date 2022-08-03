/* Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14". */
#include <iostream>
using namespace std;

#include <cstring>
void replacePi(char input[]) 
{
    int length = strlen(input);
    if (length <= 1)
        return;
    replacePi(input + 1);
    if (input[0] == 'p' and input[1] == 'i')
    {
        int count = strlen(input);
        for (int i = count + 1; i >= 2; i--)
            input[i + 2] = input[i];
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
    }
}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}