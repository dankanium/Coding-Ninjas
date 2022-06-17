#include<iostream>
#include<cmath> 
using namespace std;
int main()
{
    int basic;
    char grade;
    cin >> basic >> grade;
    double hra = 0.2 * basic;
    double da = 0.5 * basic;
    int allow;
    if (grade == 65)
        allow = 1700;
    else if (grade == 66)
        allow = 1500;
    else
        allow = 1300;
    double pf = 0.11 * basic;
    int total = round(basic + hra + da + allow - pf);
    cout << total;
}