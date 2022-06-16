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
    // 1st approach

    // for (;d > 0; d--)
    // {
    // int temp = input[0];
    // for (int i = 0; i < n; i++)
    // {
    // if (i == n - 1)
    // {
    // input[n - 1] = temp;
    // break;
    // }
    // input[i] = input[i + 1];
    // }
    // }

    // 2nd approach

    // int temp[d];
    // for (int i = 0; i < d; i++)
    // {
    //     temp[i] = input[i];
    // }
    // for (int i = d; i < n; i++)
    // {
    //     input[i - d] = input[i];
    // }
    // for (int i = n - d, k = 0; i < n; k++, i++)
    // {
    //     input[i] = temp[k];
    // }

    // 3rd approach
    reverse(input, d);
    reverse(input, n);
    reverse(input, n - d);
    // for (int i = n - d, k = 0; i <= ((n - d) + (n - 1))/2 ; k++, i++)
    // {
    // int temp = input[i];
    // input[i] = input[n - 1 - k];
    // input[n - 1 - k] = temp;
    // }
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