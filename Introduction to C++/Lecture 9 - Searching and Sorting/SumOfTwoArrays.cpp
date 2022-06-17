#include <iostream>
using namespace std;

// void sumOfTwoArrays(int *input1, int size1, int *input2, int size2, int *output)
// {
//     int size3, j, i, k; 
//     int carry = 0;
//     if (size1 > size2)
//         size3 = size1 + 1;
//     else 
//         size3 = size2 + 1;
    
//     if (size2 == 0)
//         j = 0;
//     if (size1 == 0)
//         i = 0;
//     for (i = size1 - 1, j = size2 - 1, k = size3 - 1; k >= 0; k--)
//     {
//     	if (i != -1 && j != -1)
//         {
//             output[k] = (input1[i] + input2[j] + carry) % 10;
//             if ((input1[i] + input2[j] + carry) >= 10)
//                 carry = 1;
//             else
//                 carry = 0;
//             i--;
//             j--;
//         }
//         else if (i == -1 && j != -1)
//         {
//             output[k] = (input2[j] + carry) % 10;
//             if ((input2[j] + carry) >= 10)
//                 carry = 1;
//             else
//                 carry = 0;
//             j--;
//         }
//         else if (i != -1 && j == -1)
//         {
//             output[k] = (input1[i] + carry) % 10;
//             if ((input1[i] + carry) >= 10)
//                 carry = 1;
//             else
//                 carry = 0;
//             i--;
//         }
//         else if (i == -1 && j == -1)
//         {
//             if (carry)
//                 output[k] = 1;
//             else
//                 output[k] = 0;
//         }
//     }
// }
void sumOfTwoArrays(int *input1, int size1, int *input2, int size2, int *output  )
{
    int i = size1 -1;
    int j = size2 -1;
    int carry = 0;
    int k = max(size1, size2);
                  
    while(i>=0 && j>=0)
    {
        int sum = input1[i]+ input2[j] + carry;
        output[k] = sum%10;
        carry = sum/10;
        i--;
        j--;
        k--;
    }
    while (i>=0){
        int sum = input1[i]+carry;
        output[k]=sum%10;
        carry = sum/10;
        i--;
        k--;

    }while(j>=0){
        int sum = input2[j]+carry;
        output[k]= sum%10;
        carry = sum/10;
        j--;
        k--;
    }
    output[0] = carry;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size1;
		cin >> size1;

		int *input1 = new int[size1];

		for (int i = 0; i < size1; ++i)
		{
			cin >> input1[i];
		}

		int size2;
		cin >> size2;

		int *input2 = new int[size2];

		for (int i = 0; i < size2; ++i)
		{
			cin >> input2[i];
		}

		int outsize = 1 + max(size1, size2);

		int *output = new int[outsize];

		sumOfTwoArrays(input1, size1, input2, size2, output);

		for (int i = 0; i < outsize; ++i)
		{
			cout << output[i] << " ";
		}

		delete[] input1;
		delete[] input2;
		delete[] output;
		cout << endl;
	}

	return 0;
}