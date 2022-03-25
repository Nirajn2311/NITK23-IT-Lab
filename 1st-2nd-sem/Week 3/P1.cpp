#include<iostream>

using namespace std;

int main()
{
	char d;
	do
	{
	cout<<"ENTER THE OPERATION YOU WANT TO PERFORM"<<endl;
	cout<<"1.ADDITION"<<endl<<"2.SUBTRACTION"<<endl<<"3.MULTIPLICATION"<<endl<<"4.DIVISION"<<endl;
	cout<<"ENTER AN OPTION: ";
	int x,a,b;
	float result;
	cin>>x;
	switch(x)
	{
		case 1:
		cout<<"Enter the 2 numbers : "<<endl;
		cin>>a>>b;
		result=a+b;
		cout<<"The sum is : "<<result<<endl;
		break;
		case 2:
		cout<<"Enter the 2 numbers : "<<endl;
		cin>>a>>b;
		result=a-b;
		cout<<"Difference is : "<<result<<endl;
		break;
		case 3:
		cout<<"Enter the 2 numbers : "<<endl;
		cin>>a>>b;
		result=a*b;
		cout<<"Product is : "<<result<<endl;
		break;
		case 4:
		div:
		cout<<"Enter the 2 numbers : "<<endl;
		cin>>a>>b;
		if(b==0)
		{
			cout<<"DIVISION BY ZERO!!"<<endl;
			cout<<"Enter numbers again"<<endl;
			goto div;
		}
		result=(float)a/b;
		cout<<"The quotient is : "<<result<<endl;
		break;
	}
	cout<<"Do you want to do another calculation. If yes type 'Y' if no type 'N'"<<endl;
	cin>>d;
	} while(d=='Y' || d=='y');
	return 0;
}
	