/* BISECTION METHOD to find root of the equation

f(x) = x-x^2-25

user input two values

*/

#include<iostream>
using namespace std;

float f(float x)
{
	return (x*x-25);
}

int main()
{
	cout<<"\nEnter two values such that f(x) has opposite sign :";
	float a,b,c;
	cout<<"\nFirst value : ";
	cin>>a;
	cout<<"\nSecond Value : ";
	cin>>b;
	if(f(a)<0)
	{
		b=a+b;
		a=b-a;
		b=b-a;
	}
	
	while(1)
	{
		c=(a+b)/2.0;
		if(f(c)>0)
		{
			a=c;
		}
		else if(f(c)<0)
		{
			b=c;
		}
		else
		{
			break;
		}	
	}
	
	cout<<"\nRoot of the equation is "<<c;
return 0;
}

/*
output

Enter two values such that f(x) has opposite sign :
First value : 2.2

Second Value : 7.5

Root of the equation is 5
------------------------------------------------------

Enter two values such that f(x) has opposite sign :
First value : 1

Second Value : 8

Root of the equation is 5
---------------------------------------------------------

Enter two values such that f(x) has opposite sign :
First value : 4

Second Value : 6

Root of the equation is 5

*/
