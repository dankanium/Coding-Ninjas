/* Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*". */

#include <iostream>
using namespace std;
#include <cstring>
void pairStar(char input[]) {
    int len = strlen(input);
    if (len == 0)
        return;    
    pairStar(input + 1);
    cout << len << endl;
    if (input[0] == input[1])
    {
        int count = strlen(input); // we only need to shift right from where doubles were found, using len would shift the whole string making no difference
        for (int i = count + 1; i >= 1; i--)
        {
            input[i + 1] = input[i];
        }
        input[1] = '*';
    }
}
int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}