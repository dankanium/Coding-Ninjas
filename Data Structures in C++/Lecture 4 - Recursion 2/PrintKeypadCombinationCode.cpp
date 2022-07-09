#include <bits/stdc++.h>
using namespace std;
string key[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void helper(int num, string output)
{
    if (num == 0 or num == 1)
    {
        cout << output << endl;
        return;
    }
    string keyVal = key[num % 10];
    for (int i = 0; i < keyVal.size(); i++)
    {
        helper(num / 10, keyVal[i] + output);
    }

}
void printKeypad(int num)
{
    string output = "";
    helper(num, output);
}
int main()
{
    int num;
    cin >> num;
    printKeypad(num);
    return 0;
}