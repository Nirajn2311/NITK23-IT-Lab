#include<iostream>

using namespace std;

class Time
{
    private:
        int h,m,s;

    public:
        Time()
        {
            h=m=s=0;
        }
        Time(int hr, int min,int sec)
        {
            h=hr;
			m=min;
            s=sec;
        }
        void display()
        {
            cout<<"Time: "<<h<<":"<<m<<":"<<s<<"\n";
        }
};

int main()
{
    Time t1;
    t1.display();
    Time t2(10,25,30);
    t2.display();
}