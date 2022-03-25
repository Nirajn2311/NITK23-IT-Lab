#include <iostream>
#include <string>

using namespace std;

class stud
{
private:
    char name[30], branch[30];
    int rno, sem;

public:
    void input();
    void display();
};

void stud::input()
{
    cout << "Enter reg number of student: ";
    cin >> rno;
    cout << "Enter name of student: ";
    cin >> name;
    cout << "Enter branch of student: ";
    cin >> branch;
    cout << "Enter semester of student: ";
    cin >> sem;
}

void stud::display()
{
    cout << "\n\nReg Number: " << rno
         << "\nName: " << name
         << "\nBranch: " << branch
         << "\nSemester: " << sem
		 << endl;
}

int main()
{
    stud s;
    s.input();
    s.display();
    return 0;
}