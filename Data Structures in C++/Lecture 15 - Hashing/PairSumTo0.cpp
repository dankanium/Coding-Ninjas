#include<bits/stdc++.h>
using namespace std;
int pairSum(int *arr, int n)
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[arr[i]]++;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
     	if (map[-arr[i]] > 0)
        {
            count++;
            map[-arr[i]]--;
        }
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << pairSum(arr, n);
    delete[] arr;
    return 0;
}