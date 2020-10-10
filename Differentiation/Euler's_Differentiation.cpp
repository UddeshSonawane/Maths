/*EULAR DIFFERENTIATION

this method is used to find the value of differentiation at some value x using the differential equation

here, the equation given is not the simple f(x). It is f'(x)
      
question :
	y' + 2y = 2 - e^(-4t)        & y(0)=1
	use Eular method

for simplicity, we may right it as

	y' + 2y = 2 - 1/(e^(4t))

given : x0=0
        y0=1

        step size = h =(as per user... smaller the h, lesser the error)

using formla:  y<n+1> = y<n> + h*f(x<n>,y<n>)

	f(x<n>,y<n>)  -> is the value of differential equation at points (x,y)


*/

#include<iostream>
#include<cmath>
using namespace std;

#define e 2.718

float f(float x, float y)
{
	return (2-2*y-1/(pow(e,4*x)));
}

int main()
{
	float x0,y0,temp_x,temp_y;
	cout<<"\nEnter initial point coordinates";
	cout<<"\nEnter x0 : ";
	cin>>x0;
	cout<<"\nEnter y0 : ";
	cin>>y0;
	temp_x=x0;
	temp_y=y0;
	
	float x;
	cout<<"\nEnter x to find differential at : ";
	cin>>x;
	
	int n;
	cout<<"\nEnter number of partitions to make to result : ";
	cin>>n;
	
	float h;
	h=(x-x0)/n;
	
	cout<<"\n**** step size : "<<h;
	
	float answer;
	answer=0;
	for(int i=0;i<n;i++)
	{
		answer=temp_y+h*f(temp_x,temp_y);
		temp_x=temp_x+h;
		temp_y=answer;
	}
	
	cout<<"\nAnswer of differential at x="<<x<<" : "<<answer; 
return 0;
}

/*
output

Enter initial point coordinates
Enter x0 : 0

Enter y0 : 1

Enter x to find differential at : 0.5

Enter number of partitions to make to result : 4

**** step size : 0.125
Answer of differential at x=0.5 : 0.842229

-------------------------------------------------------------

Enter number of partitions to make to result : 10

**** step size : 0.05
Answer of differential at x=0.5 : 0.868733

----------------------------------------------------

Enter number of partitions to make to result : 50

**** step size : 0.01
Answer of differential at x=0.5 : 0.880871

---------------------------------------------------  actual answer : 0.883727921 
*/
