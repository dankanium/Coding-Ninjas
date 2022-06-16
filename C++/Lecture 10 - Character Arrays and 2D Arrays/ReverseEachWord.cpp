#include <iostream>
#include <cstring>
using namespace std;

#include<cstring>
void removeConsecutiveDuplicates(char input[]) {
    int len = strlen(input);
    int current = 1, next = 1;
    char lastchar = input[0];
    while(next < len) {
        if(input[next] == lastchar) {
            next++;
        }
        else
        {
            input[current] = input[next];
            lastchar = input[next];
            next++;
            current++;
        }
        if(next == len)
        {
            input[current] = '\0';
        }
    }
}

int main() {
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    reverseEachWord(str);
    cout << str;
}