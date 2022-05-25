#include <iostream>
using namespace std;

void arrange(int *arr, int n)
{
    //Write your code here
    if (n!=0)
    {
        int count = 1;
        for (int i = 0; i <= (n-1)/2; i++)
        {
            arr[i] = count;
            count++;
            if (count > n and n%2 != 0)
                break;
            arr[n-1-i] = count;
            count++;  
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
		cin >> n;

		int *arr = new int[n];
		arrange(arr, n);
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		delete [] arr;
	}