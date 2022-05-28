#include <iostream>
using namespace std;

void insertionSort(int *input, int size)
{
    for (int i = 0; i < size; i++)
    {
        int temp = input[i];
        for (int j = i - 1; j >= 0 and temp < input[j]; j--)
        {
            input[j+1] = input[j];
            input[j] = temp;
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
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		insertionSort(input, size);

		for (int i = 0; i < size; i++)
		{
			cout << input[i] << " ";
		}

		delete[] input;
		cout << endl;
	}

	return 0;
}