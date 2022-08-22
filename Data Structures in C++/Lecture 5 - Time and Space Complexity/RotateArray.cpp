#include <iostream>
using namespace std;
void reverse(int *input, int n)
{
    for (int i = 0; i <= (n - 1) / 2; i++)
    {
        int temp = input[i];
        input[i] = input[n - 1 - i];
        input[n - 1 - i] = temp;
    }
}
void rotate(int *input, int d, int n)
{
    reverse(input, d);
    reverse(input, n);
    reverse(input, n - d);
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

        for (int i = 0; i < size; ++i)
        {
            cin >> input[i];
        }

        int d;
        cin >> d;

        rotate(input, d, size);

        for (int i = 0; i < size; ++i)
        {
            cout << input[i] << " ";
        }

        delete[] input;
        cout << endl;
    }

    return 0;
}