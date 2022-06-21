/* Given a string, compute recursively a new string where all 'x' chars have been removed. */

#include <iostream>
using namespace std;
#include <cstring>
void removeX(char input[]) {
    int len = strlen(input);
    if (len == 0)
        return;
    removeX(input+1);
    if (input[0] == 'x')
        for (int i = 1; i <= len; i++)
            input[i - 1] = input[i];
}
int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}   