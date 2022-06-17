#include <iostream>
using namespace std;

#include <climits>
void findLargest(int **input, int nRows, int mCols)
{
    //Write your code here
    int row_sum = 0, col_sum = 0;
    int max = INT_MIN;
    int index = 0;
    bool row = 1;
    for (int i = 0; i < nRows; i++)
    {
        row_sum = 0;
        for (int j = 0; j < mCols; j++)
        {
            row_sum += input[i][j];
        }
        if (row_sum > max)
        {
            max = row_sum;
            index = i;
            row = 1;
        }
    }
    for (int i = 0; i < mCols; i++)
    {
        col_sum = 0;
        for (int j = 0; j < nRows; j++)
        {
            col_sum += input[j][i];
        }
        if (col_sum > max)
        {
            max = col_sum;
            index = i;
            row = 0;
        }
    }
    if (row)
    {
        cout << "row " << index << " " << max << endl;
    }
    else 
    {
        cout << "column " << index << " " << max << endl;
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

		int **input = new int *[row];
		for (int i = 0; i < row; i++)
		{
			input[i] = new int[col];
			for (int j = 0; j < col; j++)
			{
				cin >> input[i][j];
			}
		}

		findLargest(input, row, col);
		cout << endl;
	}
}