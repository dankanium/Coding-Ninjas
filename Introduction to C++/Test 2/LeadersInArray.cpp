#include<iostream>
#include<climits>
using namespace std;
void Leaders(int* arr,int len)
{
	int largest = -99999999, j = 0;
    int *leaders = new int[len];
    for (int i = len - 1; i >= 0; i--)
    {
        if (arr[i] >= largest)
        {
            leaders[j] = arr[i];
            j++;
            largest = arr[i];
        }
    }
    for (int i = j - 1; i >= 0; i--)
    {
        cout << leaders[i] << " ";
    }
}
int main()
{
    int len;
    cin>>len;
	int *arr = new int[len + 1];
	
	for(int i=0;i<len;i++)
	{
		cin>>arr[i];
	}
	Leaders(arr,len);
}
