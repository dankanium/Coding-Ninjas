#include <iostream>
#include <algorithm>
using namespace std;
// Sort both array and use two pointers. If arr1's element is small, increase by 1 and vice versa.
void intersection(int *arr1, int *arr2, int n, int m) 
{
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + n);
    int i = 0, j = 0;
    while (j < m and i < n)   // j < m means that arr2 is always small, which is wrong. Careful.
    {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr1[i] > arr2[j])
            j++;
        else
        {
            cout << arr2[j] << " ";
            i++;
            j++;
        }
    }
    cout << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
}