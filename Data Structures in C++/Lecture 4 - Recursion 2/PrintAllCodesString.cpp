#include <iostream>
using namespace std;
#include <string.h>
using namespace std;
void helper(string input, string output)
{
    if (input[0] == '\0')
    {
        for (int i = 0; i < size; i++)
            cout << output;
        cout << endl;
        return;
    }
	int first = input[0] - '0';
    char smallChar = 'a' + first - 1;
    helper(input.substr(1), smallChar + output);
    if (input[1] != '\0')
    {
        int second = first * 10 + input[1] - 48;
        if (10 <= second <= 26)
        {
            char bigChar = second + 'a' - 1;
            helper(input.substr(2), bigChar + output);
        }
    }
}
void printAllPossibleCodes(string input) {
    string output = "";
    helper(input, output);
}

int main(){
    string input;
    cin >> input;
    printAllPossibleCodes(input);
    return 0;
}
