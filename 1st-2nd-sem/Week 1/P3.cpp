#include <iostream>

using namespace std;

class area
{
private:
    int r, l, b, ba, h;
    float ar;

public:
    void input();
    void circle();
    void rect();
    void tri();
};

void area::input()
{

    int c;
    cout << "1) Area of circle\n2) Area of rectangle\n3) Area of triangle\n";
    cout << "Enter your choice: ";
    cin >> c;
    switch (c)
    {
    case 1:
        circle();
        break;

    case 2:
        rect();
        break;

    case 3:
        tri();
        break;

    default:
        cout << "INVALID OPTION ENTERED!!!";
        break;
    }
}

void area::circle()
{
    cout << "Enter radius of circle: ";
    cin >> r;
    ar = 3.14 * r * r;
    cout << "Area = " << ar << "\n";
}

void area::rect()
{
    cout << "Enter length of rectangle: ";
    cin >> l;
    cout << "Enter breadth of rectangle: ";
    cin >> b;
    ar = l * b;
    cout << "Area = " << ar << "\n";
}

void area::tri()
{
    cout << "Enter base of triangle: ";
    cin >> ba;
    cout << "Enter height of triangle: ";
    cin >> h;
    ar = 0.5 * ba * h;
    cout << "Area = " << ar << "\n";
}

int main()
{
    area a1;
    a1.input();
    return 0;
}