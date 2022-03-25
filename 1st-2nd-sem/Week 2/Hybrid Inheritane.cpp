#include<iostream>

using namespace std;

class Student
{
private:
	char name[20], branch[20], g;
	int regno, age, sem;
public:
	void Sin()
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

	void Sout()
	{
		cout<<"Name : "<<name<<"\nReg No : "<<regno<<"\nAge : "<<age<<"\nGender : "<<g<<"\nBranch : "<<branch<<"\nSemester : "<<sem;
	}
};

class Parent
{
private:
	char Fname[20], Mname[20];
public:
	void Pin()
	{
		cout<<"Enter Fathers Name : ";
		cin>>Fname;
		cout<<"Enter Mothers Name : ";
		cin>>Mname;
	}

	void Pout()
	{
		cout<<"\nFathers Name : "<<Fname<<"\nMothers Name : "<<Mname;
	}
};

class StudentResult: public Parent, public Student
{
private:
	int tmarks;
	char grade;
	float per;
public:
	void SRin()
	{
		cout<<"Enter Total Marks : ";
		cin>>tmarks;
		cout<<"Enter Grade : ";
		cin>>grade;
		cout<<"Enter Percentage : ";
		cin>>per;
	}

	void SRout()
	{
		cout<<"\nTotal Marks : "<<tmarks<<"\nGrade : "<<grade<<"\nPercentage : "<<per;
	}
};

class Health: public StudentResult
{
private:
	char BloodType[5];
	int MedID;
public:
	void Hin()
	{
		cout<<"Enter Med ID : ";
		cin>>MedID;
		cout<<"Enter Blood Type : ";
		cin>>BloodType;
	}
	void Hout()
	{
		cout<<"\nMed ID : "<<MedID<<"\nBlood Type : "<<BloodType;
	}
};

int main()
{
	StudentResult S1;
	Health S2;
	S1.Sin();
	S1.SRin();
	S1.Pin();
	S2.Hin();
	S1.Sout();
	S1.SRout();
	S1.Pout();
	S2.Hout();
	cout<<endl;
	return 0;
}
