#include <iostream>
#include <string>
using namespace std;
void helper(string input, string output[], int size)
{
    if (input[0] == '\0')
    {
        for (int i = 0; i < size; i++)
        {
            cout << output[i] << " ";
        }
        return;
    }
    int k = 0;
    for (int i = 0; i < input.size(); i++)
    {
        string smallOutput[10000];
        helper(input.substr(0, i) + input.substr(i + 1), smallOutput, size + 1);
        for (int j = 0; j < size; j++)
        {
            output[k++] = input[i] + smallOutput[j];
        }
    }
}

void printPermutations(string input)
{
    string output[10000];
    helper(input, output, 0);
}

int main()
{
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}