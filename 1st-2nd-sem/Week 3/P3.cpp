#include<iostream>

using namespace std;

class Date
{
	int d,m,y;

	public:
		void input();
		void display();
};

class Hospital
{
	char name[30], disease[30];
	Date doa, dod;

	public:
		void input();
		void display();
};

class Age: public Hospital
{
	public:
		int age;
		void input();
		void display();
};

void Date::input()
{
	cout<<"\nEnter date: ";
	cin>>d;
	cout<<"Enter month: ";
	cin>>m;
	cout<<"Enter year: ";
	cin>>y;	
}

void Date::display()
{
	cout<<d<<"/"<<m<<"/"<<y;
}

void Hospital::input()
{
	cout<<"\nEnter name of patient: ";
	cin>>name;
	cout<<"Enter date of admission: ";
	doa.input();
	cout<<"\nEnter disease: ";
	cin>>disease;
	cout<<"Enter date of discharge: ";
	dod.input();
}

void Hospital::display()
{
	cout<<"\n\nPatient Name: "<<name;
	cout<<"\nDate of admission: ";
	doa.display();
	cout<<"\nDisease: "<<disease;
	cout<<"\nDate of discharge: ";
	dod.display();
}

void Age::input()
{
	Hospital::input();
	cout<<"\nEnter age: ";
	cin>>age;
}

void Age::display()
{
	Hospital::display();
	cout<<"\nAge: "<<age<<endl;
}

int main()
{
	int num;
	Age p1[100];
	cout<<"Enter number of patients: ";
	cin>>num;
	for(int i=0;i<num;i++)
		p1[i].input();

	cout<<"\nPaediatric Patients: ";
	for(int i=0;i<num;i++)
	{
		if(p1[i].age < 12)
			p1[i].display();
	}
	return 0;
}