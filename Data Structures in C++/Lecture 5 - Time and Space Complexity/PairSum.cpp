#include<bits/stdc++.h>
using namespace std;
int pairSum(int *arr, int n, int sum)
{
    sort(arr, arr + n);
    int pairCount = 0;
    int startIndex = 0, endIndex = n - 1;
    while (startIndex < endIndex)
    {
        if (arr[startIndex] + arr[endIndex] < sum)
            startIndex++;
        else if (arr[startIndex] + arr[endIndex] > sum)
            endIndex--;
        else
        {
            int startElement = arr[startIndex];
            int endElement = arr[endIndex];
            if (startElement == endElement)
            {
                int totalElements = endIndex - startIndex;
                
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int sum;
        cin >> sum;
        cout << pairSum(arr, n, sum);
        cout << endl;
        delete[] arr;
    }
}