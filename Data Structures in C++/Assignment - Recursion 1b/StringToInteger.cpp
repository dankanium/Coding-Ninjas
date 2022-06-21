/* Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer. */

#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int stringToNumber(char input[]) {
	int len = strlen(input);
    if (len == 0)
        return 0;
    int ans = stringToNumber(input + 1);
    ans += (input[0] - '0') * (pow(10, len - 1));
    return ans;
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}