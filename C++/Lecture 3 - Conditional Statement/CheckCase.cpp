#include<iostream>
using namespace std;

int main() {
	// Write your code here
    char c;
    cin >> c;
    if (65 <= c and c <= 90)
    	cout << 1;
    else if (97 <= c and c <= 122)
        cout << 0;
    else
        cout << -1;
	
}
