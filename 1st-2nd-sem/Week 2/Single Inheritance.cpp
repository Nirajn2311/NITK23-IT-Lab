#include<iostream>

using namespace std;

class Student
{
private:
	char name[20], branch[20], g;
	int regno, age, sem;
public:
	void input()
	{
		cout<<"Enter Name : ";
		cin>>name;
		cout<<"Enter Reg No : ";
		cin>>regno;
		cout<<"Enter Age : ";
		cin>>age;
		cout<<"Enter Gender : ";
		cin>>g;
		cout<<"Enter Branch : ";
		cin>>branch;
		cout<<"Enter Semester : ";
		cin>>sem;
	}

	void display()
	{
		cout<<"\nName: "<<name<<"\nReg No: "<<regno<<"\nAge: "<<age<<"\nGender: "<<g<<"\nBranch: "<<branch<<"\nSemester: "<<sem;
	}
};


class StudentResult: public Student
{
private:
	int tmarks;
	char grade;
	float per;
public:
	void insert()
	{
		cout<<"Enter Total Marks : ";
		cin>>tmarks;
		cout<<"Enter Grade : ";
		cin>>grade;
		cout<<"Enter Percentage : ";
		cin>>per;
	}

	void output()
	{
		cout<<"\nTotal Marks : "<<tmarks<<"\nGrade : "<<grade<<"\nPercentage : "<<per<<endl;
	}
};

int main()
{
	StudentResult S1;
	S1.input();
	S1.insert();
	S1.display();
	S1.output();
	return 0;
}
