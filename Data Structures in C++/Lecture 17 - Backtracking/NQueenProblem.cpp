#include<bits/stdc++.h>
using namespace std;
int board[11][11];
bool flag = true;
bool isPossible(int n, int row, int col)
{
    // same column
    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][col] == 1)
            return false;
    }
    // upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }
    // upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0, j < n; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }
    return true;
}
void placeNQueensHelper(int n, int row)
{
    // base case when last row is filled, print
    if (n == row)
    {
        if (flag == true)
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << board[i][j] << " ";
                }
                cout << endl;
            }
        flag = false;
        return;
    }
    // traversing current row
    for (int j = 0; j < n; j++)
    {
        // check if place is possible
        if (isPossible(n, row, j)) 
        {
            board[row][j] = 1;
            placeNQueensHelper(n, row + 1);
            // setting 0 otherwise, if 1 till nth row, its already printed
            board[row][j] = 0;
        }
    }
}
void placeNQueens(int n)
{
    // set every element as 0
    memset(board, 0, 11 * 11 * sizeof(int));
    placeNQueensHelper(n, 0);
}
int main()
{
    int n;
    cin >> n;
    placeNQueens(n);
    if (flag == true)
        cout << "Not possible" << endl;
    return 0;
}