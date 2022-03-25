#include<iostream>

using namespace std;

class tollbooth
{
	unsigned int number;
	double money;
public:
	tollbooth()
	{
		number=0;
		money=0.0;

	}
	void payingvehicles()
	{
		number++;
		money+=50;

	}
	void nonpayingvehicle()
	{
		number++;
	}
	void displaycashcollected()
	{
		cout<<"Number of passing vehicles is: "<<number<<endl;
		cout<<"Money collected is: "<<money<<endl;
	}
};

int main()
{
	char a;
	tollbooth t;
	do
	{
	cout<<"Enter 0 for paying and 1 for non paying"<<endl;
	int x;
	cin>>x;
	switch(x)
	{
		case 0:
		t.payingvehicles();
		break;
		case 1:
		t.nonpayingvehicle();
		break;

	}

	cout<<"Do you want to continue. If yes type 'Y' if no type 'N'"<<endl;
	cin>>a;
	} while(a=='Y' || a=='y');
	t.displaycashcollected();
	return 0;
}
