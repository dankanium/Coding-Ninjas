#include<bits/stdc++.h>
using namespace std;
void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1 + i; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    selectionsort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}