#include<iostream>
#include<climits>
using namespace std;

void Leaders(int* arr,int len)
{
    int leader = arr[0];
    int i = 0, j;
    bool flag = false;
    while (i <= len)
    {
        j = i + 1;
        while (arr[j] <= arr[i] and j <= len)
        {
            if (j == len - 1)
                flag = true;
            j++;
            continue;
        }
        if (flag)
        {
            cout << arr[i] << " ";
        }
        flag = false;
        i++;
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
