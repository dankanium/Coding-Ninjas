#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int input[], int start, int end)
{
    int small_count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (input[i] < input[start])
            small_count++;
    }
    int partition = start + small_count;
    swap(input[start], input[partition]);
    int i = start, j = end;
    while (i < j)
    {
        if (input[i] < input[partition])
            i++;
        else if (input[j] >= input[partition])
            j--;
        else
            swap(input[i++], input[j--]);
    }
    return partition;
}

void sort(int input[], int start, int end)
{
    if (start >= end)
        return;
    int c = partition(input, start, end);
    sort(input, start, c - 1);
    sort(input, c + 1, end);
}

void quickSort(int input[], int size)
{
    sort(input, 0, size - 1);
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    quickSort(input, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
}