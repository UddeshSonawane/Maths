/*
Lagrange Interpolation 

It is applicable even when the given data points are not equidistant.
It is preferred over Newton's Divided Difference.
As it's accuracy is more.

It is given as

p(x) = SUM of Pj(x) from j=1 to n

          .......... where Pj(x) = Yj * PRODUCT of ((x-xk)/(xj-xk)) from k=1 to n where k!=j

i.e.,

       (x-x2)(x-x3)...(x-xn)          (x-x1)(x-x3)...(x-xn)
p(x) = ------------------------- y1 + ------------------------ y2 + -----
       (x1-x2)(x1-x3)...(x1-xn)       (x2-x1)(x2-x3)...(x2-xn)


example

x    y
0    1
1    3
3    49
4    129
7    813

find value at x=0.3

*/



#include<iostream>
using namespace std;

float fun(int i, float x[], int n, float test_data)
{
	float val,temp1=1,temp2=1;
	for(int j=0;j<n;j++)
	{
		if(j==i)
		{
			continue;
		}
		else
		{
			temp1=temp1*(test_data-x[j]);
			temp2=temp2*(x[i]-x[j]);
			//cout<<"("<<test_data<<"-"<<x[j]<<")";
			//cout<<"("<<x[i]<<"-"<<x[j]<<")";
		}
	}
	val=temp1/temp2;
	//cout<<"\nVal : "<<val;
return val;
}

int main()
{
	int n=5; // as we are considering for 5 datapoints. It may vary if we take user input
	float x[] = {0,1,3,4,7};
	float y[] = {1,3,49,129,813};
	float value=0;
	float test_data;
	cout<<"\nEnter test data : ";
	cin>>test_data;
	
	for(int i=0;i<n;i++)
	{
		value=value+fun(i,x,n,test_data)*y[i];
	}
	
	cout<<"\nValue at x="<<test_data<<"  -->  "<<value;
	
return 0;
}

/*

output

Enter test data : 0

Value at x=0  -->  1
---------------------------------

Enter test data : 4

Value at x=4  -->  129
-----------------------------------

Enter test data : 0.3

Value at x=0.3  -->  1.831

*/
