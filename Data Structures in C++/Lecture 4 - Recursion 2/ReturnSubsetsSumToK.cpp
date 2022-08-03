#include <iostream>
using namespace std;
int subsetSumToK(int input[], int length, int output[][50], int k)
{
    if (k == 0)
    {
        output[0][0] = 0;
        return 1;
    }
    if (length <= 0)
    {
        return 0;
    }
    int o1[1000][50], o2[1000][50];
    int x = subsetSumToK(input + 1, length - 1, o1, k - input[0]);
    int y = subsetSumToK(input + 1, length - 1, o2, k);
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j <= o2[i][0]; j++)
        {
            output[i][j] = o2[i][j];
        }
    }
    for (int i = 0; i < x; i++)
    {
        output[y + i][0] = o1[i][0] + 1;
        output[y + i][1] = input[0];
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 1; j < output[y + i][0]; j++)
        {
            output[y + i][j + 1] = o1[i][j];
        }
    }
    return (x + y);
}
int main()
{
    int input[20], length, output[1000][50], k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    cin >> k;
    int size = subsetSumToK(input, length, output, k);
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}