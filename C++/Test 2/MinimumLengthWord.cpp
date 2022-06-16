#include<iostream>
using namespace std;

#include <cstring>
void minLengthWord(char input[], char output[]){
    int minLen = 999999, currentStart = 0, minStart;
	for (int i = 0; i <= strlen(input); i++)
    {
        if (input[i] == ' ' or input[i] == '\0')
        {
            int currentLen = i - currentStart;
            if (currentLen < minLen)
            {
                minLen = currentLen;
                minStart = currentStart;
            }
            currentStart = i + 1;
        }
    }
    int k = 0;
    for (int j = minStart; k < minLen;)
    {
        output[k++] = input[j++];
    }
    output[k] = '\0';
}

int main(){
  char ch[10000], output[10000];
  cin.getline(ch, 10000);
  minLengthWord(ch, output);
  cout << output << endl;
}