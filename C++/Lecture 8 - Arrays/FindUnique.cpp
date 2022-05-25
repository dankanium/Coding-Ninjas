#include <iostream>
using namespace std;
int findUnique(int *arr, int size)
{
    // for (int i = 0; i < size - 1; i++)
    // {
    //     for (int j = i + 1; j < size; j++)
    //     {
    //         if (arr[i] == arr[j])
    //         {
    //             arr[i] = -1;
    //             arr[j] = -1;
    //             break;
    //         }
    //     }
    // }
    // for (int i = 0; i < size; i++)
    // {
    //     if (arr[i] != -1)
    //         return arr[i];
    // }
    
    // better approach below for if array has negative values and also it is more efficient

    for (int i = 0; i < size; i++)
    {
        bool flag = false;
        for (int j = 0; j < size; j++)
        {
            if (i!=j)
            {
                if (arr[i] == arr[j])
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag == false)
            return arr[i];
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

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		cout << findUnique(input, size) << endl;
	}

	return 0;
}