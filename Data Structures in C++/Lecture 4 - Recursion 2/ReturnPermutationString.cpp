#include <iostream>
#include <string>
using namespace std;
#include <string>
using namespace std;

int returnPermutations(string input, string output[])
{
    if (input[0] == '\0')
    {
        output[0] = "";
        return 1;
    }
    int k = 0;
    for (int i = 0; i < input.size(); i++)
    {
        string smallOutput[1000];
        int smallSize = returnPermutations(input.substr(0, i) + input.substr(i + 1), smallOutput);
        for (int j = 0; j < smallSize; j++)
        {
            output[k++] = input[i] + smallOutput[j];
        }
    }
    return k;
}
int main()
{
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
