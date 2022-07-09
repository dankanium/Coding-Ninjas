#include<bits/stdc++.h>
using namespace std;
int keypad(int num, string output[])
{
    if (num == 0 or num == 1)
    {
        output[0] = "";
        return 1;
    }
    string key[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string keyVal = key[num % 10];
    int smallOutputSize = keypad(num / 10, output);
    string temp[smallOutputSize];
    for (int i = 0; i < smallOutputSize; i++)
        temp[i] = output[i];
    int count = 0;
    for (int i = 0; i < keyVal.size(); i++)
    {
        for (int j = 0; j < smallOutputSize; j++)
        {
            output[count++] = temp[j] + keyVal[i];
        }
    }
    return count;
}
int main()
{
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}