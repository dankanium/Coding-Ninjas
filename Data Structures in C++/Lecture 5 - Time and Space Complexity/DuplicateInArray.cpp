#include <iostream>
using namespace std;

int findDuplicate(int *arr, int n)
{
    int arrSum = 0;               // Numbers range from 0 - (N-2). Find sum of this and substract form the sum of the array. Difference is ans.
    for (int i = 0; i < n; i++)
    {
        arrSum += arr[i];
    }
    int sum = ((n-2)*(n-1))/2;
    return arrSum - sum;
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

        cout << findDuplicate(input, size) << endl;
    }

    return 0;
}