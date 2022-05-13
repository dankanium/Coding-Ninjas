#include<iostream>
using namespace std;


int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
    int n; cin >> n;
    int i = 1;
    int odd = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= n-i)
        {
            cout << " ";
            j++;
        }
        j = 1;
        while (j <= odd)
        {
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
        odd+=2;
    }
  
}