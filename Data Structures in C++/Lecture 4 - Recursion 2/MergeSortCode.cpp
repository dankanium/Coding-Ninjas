#include <iostream>
using namespace std;

void merge(int input[], int start, int end, int mid)
{
    int size = (end - start) + 1;
    int ans[size];
    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end)
    {
        if (input[i] < input[j])
            ans[k++] = input[i++];
        else
            ans[k++] = input[j++];
    }
    while (i <= mid)
        ans[k++] = input[i++];

    while (j <= end)
        ans[k++] = input[j++];

    for (int k = 0, i = start; i <= end;)
    {
        input[i++] = ans[k++];
    }
}

void sort(int input[], int start, int end)
{
    if (start >= end)
        return;
    int mid = (start + end) / 2;
    sort(input, start, mid);
    sort(input, mid + 1, end);
    merge(input, start, end, mid);
}

void mergeSort(int input[], int size)
{
    sort(input, 0, size - 1);
}

int main()
{
    int length;
    cin >> length;
    int *input = new int[length];
    for (int i = 0; i < length; i++)
        cin >> input[i];
    mergeSort(input, length);
    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }
}