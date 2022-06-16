#include <iostream>
#include <cstring>
using namespace std;

bool isPermutation(char input1[], char input2[]) {
    if (strlen(input1) == strlen(input2))
    {
		// int l = strlen(input1);
		// for (int i = 0; i < l; i++)
		// {
		// for (int j = 0; j < l; j++)
		// {
		// if (input1[i] == input2[j])
		// {
		// input2[j] = 1;
		// break;
		// }
		// else if (j == l - 1)
		// return false;
		// }
		// }
		// return true;
        
        int length = strlen(input1);
        int freq[256] = {0};
        for (int i = 0; i < length; i++)
        {
            freq[input1[i]]++;
        }
        for (int i = 0; i < length; i++)
        {
            freq[input2[i]]--;
        }
        for (int i = 0; i < 256; i++)
        {
            if (freq[i] != 0)
                return false;
        }
        return true;
    }
    else
        return false;
}

int main() {
    int size = 1e6;
    char str1[size];
    char str2[size];
    cin >> str1 >> str2;
    cout << (isPermutation(str1, str2) ? "true" : "false");
}