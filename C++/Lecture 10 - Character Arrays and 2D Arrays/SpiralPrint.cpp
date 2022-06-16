#include <iostream>
using namespace std;

void spiralPrint(int **arr, int n, int m)
{
    //Write your code here
    int rs = 0, re = n - 1;
    int cs = 0, ce = m - 1;
    int count = n*m;
    while (count)
    {
        for (int i = cs; i <= ce; i++)
        {
            cout << arr[rs][i] << " ";
            count--;
        }
        rs++;
        for (int i = rs; i <= re; i++)
        {
            cout << arr[i][ce] << " ";
            count--;
        }
        ce--;
        for (int i = ce; i >= cs; i--)
        {
            cout << arr[re][i] << " ";
            count--;
        }
        re--;
        for (int i = re; i >= rs; i--)
        {
            cout << arr[i][cs] << " ";
            count--;
        }
        cs++;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int row, col;
        cin >> row >> col;
        int **matrix = new int *[row];

        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
        spiralPrint(matrix, row, col);

        for (int i = 0; i < row; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        cout << endl;
    }
}