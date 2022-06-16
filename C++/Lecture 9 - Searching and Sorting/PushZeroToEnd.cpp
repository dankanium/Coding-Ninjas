#include <iostream>
using namespace std;

void pushZeroesEnd(int *input, int size)
{
    // Write your code here
    for (int i = 0, k = 0; i < size; i++)
    {
        if (input[k] == 0 and input[i] != 0)
        {
            input[k] = input[i];
            input[i] = 0;
            k++;
        }
        else if (input[k] != 0)
        {
            k++;
        }
    }
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int size;

        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }

        pushZeroesEnd(input, size);

        for (int i = 0; i < size; i++)
        {
            cout << input[i] << " ";
        }

        cout << endl;
        delete[] input;
    }

    return 0;
}