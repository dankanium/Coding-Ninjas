#include <iostream>
#include <cstring>
#include<string>
using namespace std;

string getCompressedString(string &input) {
    int count = 1;
    string ans = "";
    for (int i = 0; i < input.size(); i++)
    {
        while (i < input.size() and input[i] == input[i + 1])
        {
            count++;
            i++;
        }
        if (count == 1)
            ans += input[i];
        else
        {
            ans += input[i];
            ans += count + '0';
            count = 1;
        }
    }
    return ans;
}

int main() {
    int size = 1e6;
    string str;
    getline(cin, str);
    str = getCompressedString(str);
    cout << str << endl;
}