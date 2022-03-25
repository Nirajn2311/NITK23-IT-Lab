#include<iostream>

using namespace std;

class complex
{
	int real,imag;
	public:
	void input()
	{
		cout<<"Enter real and imaginary part: ";
		cin>>real>>imag;
		cout<<"Complex number is : "<<real<<" + i"<<imag<<endl;
	}
	void output()
	{
		cout<<"\nComplex number is : "<<real<<" + i"<<imag<<endl;
	}
	complex operator +(complex a)
	{
		complex x;
		x.real=real+a.real;
		x.imag=imag+a.imag;
		return x;
	}
};

int main()
{
	complex c1,c2,c3;
	c1.input();
	c2.input();
	c3 = c1 + c2;
	cout<<"Sum of above two complex numbers";
	c3.output();
}