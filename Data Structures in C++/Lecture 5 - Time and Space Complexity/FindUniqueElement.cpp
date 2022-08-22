#include <iostream>
using namespace std;
// Bitwise XOR. Same number XOR gives 0. 0 XOR 1 element is the unique
int findUnique(int *arr, int n) {
    int ans = arr[0];          
    for (int i = 1; i < n; i++)
    {
        ans ^= arr[i];
    }
    return ans;
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; ++i) {
            cin >> input[i];
        }

        cout << findUnique(input, size) << endl;
    }

    return 0;
}