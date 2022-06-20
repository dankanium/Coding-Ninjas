/* Given an integer N, count and return the number of zeros that are present in the given integer using recursion. */ 

#include <iostream>
using namespace std;

int countZeros(int n) {
    if (n <=9) // base case when only 1 digit, if not 0, it continues to n/10m, which in turn gives extra zero.
    {
        if(n==0)
            return 1;
        else
            return 0;
    }
   
    int count = countZeros(n/10);
    if (n%10 == 0)
        return count + 1;
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}