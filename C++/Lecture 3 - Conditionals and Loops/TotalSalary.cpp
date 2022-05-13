#include<iostream>
#include<cmath> 
using namespace std;
int main()
{
    int basic;
    char grade;
    cin >> basic >> grade;
    float hra = 0.2 * basic;
    float da = 0.5 * basic;
    int allow;
    if (grade == 'A')
        allow = 1700;
    else if (grade == 'B')
        allow = 1500;
    else if (grade == 'C')
        allow = 1300;
    float pf = 0.11 * basic;
    float total = basic + hra + da + allow - pf;
    cout << round(total);
}