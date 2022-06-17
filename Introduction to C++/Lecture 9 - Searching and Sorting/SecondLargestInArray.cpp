#include <iostream>
using namespace std;

#include <climits>
int findSecondLargest(int *input, int n)
{
    // Write your code here
    int max = INT_MIN;
    int second_max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (input[i] > max)
        {
            second_max = max;
            max = input[i];
        }
        else if (second_max < input[i] and input[i] < max)
        {
            second_max = input[i];
        }
    }
    return second_max;
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

        cout << findSecondLargest(input, size) << endl;

        delete[] input;
    }

    return 0;
}