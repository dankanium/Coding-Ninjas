/* Given the code to find out and return the number of digits present in a number recursively. But it contains few bugs, that you need to rectify such that all the test cases should pass. */
#include<iostream>
using namespace std;

int count(int n) {
    if (n == 0) {
        return 0;
    }
    int small = count(n / 10);
    int digits = small + 1;
    return digits;
}

int main(){
    int n;
    cin >> n;
  
    cout << count(n) << endl;
}


