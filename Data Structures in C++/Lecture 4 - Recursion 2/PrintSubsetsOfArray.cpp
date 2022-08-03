#include <iostream>
using namespace std;
void helper(int input[], int n, int output[], int m)
{
    if (n <= 0)
    {
        for (int i = 0; i < m; i++)
        {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }
    helper(input + 1, n - 1, output, m);
    int newOutput[1000];
    for (int i = 0; i < m; i++)
    {
        newOutput[i] = output[i];
    }
    newOutput[m] = input[0];
    helper(input + 1, n - 1, newOutput, m + 1);
}
void printSubsetsOfArray(int input[], int size)
{
    int output[1000];
    helper(input, size, output, 0);
}
int main()
{
    int input[1000], length;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    printSubsetsOfArray(input, length);
}