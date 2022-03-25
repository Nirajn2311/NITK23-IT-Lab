#include <iostream>

using namespace std;

int main()
{
    float bp, da, hra, gp;
    cout << "Enter Basic Pay of employee: ";
    cin >> bp;
    da = bp * 0.4;
    hra = bp * 0.2;
    gp = bp + da + hra;
    cout << "Employee's Gross Pay: " << gp << "\n";
    return 0;
}