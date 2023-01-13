#include <iostream>
using namespace std;

#include <cstring>
// my approach
// void helper(char input[], int start, int end) 
// {
//     input = input + 1;
//     input[strlen(input) - 1] = '\0';
// }
// bool checkPalindrome(char input[]) {
//     int len = strlen(input);
// 	if (len == 1) 
//         return true;
//     if (len == 0)
//         return true;
//     if (input[0] == input[len - 1])
//     {
//         helper(input, 0, len - 1);
//     }
//     else 
//         return false;
//     bool ans = checkPalindrome(input + 1);
//     return ans;
// }

// another approach
bool helper(char input[], int start, int end)
{
    if(start>=end)
    {
        return true;
    }
    if(input[start]!=input[end])
    {
        return false;
    }
    return helper(input,start+1,end-1);
}

bool checkPalindrome(char input[]) 
{
    return helper(input, 0, strlen(input)-1);
}

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}