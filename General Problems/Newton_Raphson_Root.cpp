/* Newton Raphson Root

conditions: 
	here we assume stopping condition as 
		root value, f(x)=0;
		so we keep on checking values of x for which f(x)=0
		
by *Uddesh

*/

#include<iostream>
using namespace std;

float f(float x)
{
	return ((x*x)-2);
}

int main()
{
	float x,d,h;   // h should be as small as possible. it's just to separate out two points
	h=0.000001;
	cout<<"\nEnter possible root value : ";
	cin>>x;
	while(f(x)>0.000001)    //if we check for equal to zero condition then it will run infinitely.
	{				    //so assumed 0.000001 as absolute zero for programming
		d=(f(x)-f(x-h))/h;   // differentiation
		x=x-f(x)/d;          // to find new value of x
		//cout<<"\n"<<x;	
	}
	cout<<"\nRoot of the equation f(x)=(x^2)-2 is: x="<<x;
	
return 0;
}

/*
output

Enter possible root value : 5

Root of the equation f(x)=(x^2)-2 is: x=1.41256
*/
