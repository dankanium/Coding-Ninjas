#include <iostream>
using namespace std;
void reverse(char input[], int i, int j)
{
    while (i <= j)
    {
        char temp = input[i];
        input[i] = input[j];
        input[j] = temp;
        i++;
		j--;
    }
}
void reverseStringWordWise(char input[]) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (input[k] != '\0')
    {
      if (input[k] != ' ')
      {
         j++;
      }
      else if (input[k] == ' ')
      {
         j--;
         reverse(input, i, j);
         i = j + 2;
         j = j + 2;
      }
      k++;
    }
    reverse(input, i, --j);
	reverse(input, 0, j);
}
int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
