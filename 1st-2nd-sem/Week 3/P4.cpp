#include<iostream>

using namespace std;

class Shape
{
	public:
	double l,b,ba,h;

	void getdatat()
	{
		cout<<"Enter the height of the triangle: ";
		cin>>h;
		cout<<"Enter the base of the triangle: ";
		cin>>ba;
	}

		
	void getdatar()
	{
		cout<<"Enter the sides of the rectangle: ";
		cin>>l>>b;
	}

};

class Rectangle: public Shape 
{
public:
	void display_area()
	{
		
		cout<<"The area of the rectangle is: "<<l*b<<endl;
	}
	
};

class Triangle: public Shape
{
	public :
	void display_area()
	{
		cout<<"The area of triangle is: "<<0.5*h*ba<<endl;
		
	}
};
int main()
{
	Triangle t;
	Rectangle r;
	t.getdatat();
	r.getdatar();
	t.display_area();
	r.display_area();
	return 0;
}