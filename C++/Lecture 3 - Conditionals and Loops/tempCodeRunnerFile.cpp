#include <iostream>
using namespace std;
int main()
{
    int s, e, w;
    cin >> s >> e >> w;
    while (s <= e)
    {
        int c = ((s - 32) * 5) / 9;
        cout << s << " " << c << endl;
        s += w;
    }
}