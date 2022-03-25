#include <iostream>

using namespace std;

int main()
{
    float f, c;
    cout << "Enter temperature in Fahrenheit: ";
    cin >> f;
    c = (f - 32) * 5 / 9;
    cout << "Temperaturte in Celsius: " << c << "\n";
    return 0;
}