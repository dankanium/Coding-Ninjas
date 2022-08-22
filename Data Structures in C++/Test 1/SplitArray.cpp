#include <iostream>
using namespace std;
bool helper(int *input, int size, int start, int lsum, int rsum)
{
    if (start == size)
        return lsum == rsum;
    if (input[start] % 5 == 0)
        lsum += input[start];
    else if (input[start] % 3 == 0)
        rsum += input[start];
    else
    {
        lsum += input[start];
        rsum += input[start];
        return lsum || rsum;
    })
}
bool splitArray(int *input, int size)
{
    return helper(input, size, 0, 0, 0);
}
int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

	
	return 0;

}
