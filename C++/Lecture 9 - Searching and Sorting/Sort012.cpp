#include <iostream>
#include <algorithm>
using namespace std;

void sort012(int *arr, int n)
{
    /*
    int count0, count1, count2;
    count0 = count1 = count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count0++;
        }
        else if (arr[i] == 1)
        {
            count1++;
        }
        else if (arr[i] == 2)
        {
            count2++;
        }
    }
    for (int i = 0; i < count0; i++)
        arr[i] = 0;
    for (int i = count0; i < count1 + count0; i++)
        arr[i] = 1;
    for (int i = count1 + count0; i < n; i++)
        arr[i] = 2;
        */
    // better approach
    for (int i = 0, zero = 0, two = n - 1; i <= two;)
    {
        if (arr[i] == 0)
        {
            arr[i] = arr[zero];
            arr[zero] = 0;
            i++;
            zero++;
        }
        else if (arr[i] == 2)
        {
            arr[i] = arr[two];
            arr[two] = 2;
            two--;
        }
        else if (arr[i] == 1)
        {
            i++;
        } 
    }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int size;

		cin >> size;
		int *arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}

		sort012(arr, size);

		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}

		delete[] arr;
		cout << endl;
	}

	return 0;
}