/*

RICHARDSON EXTRAPOLATION DIFERENTIATION

F(X) = 5*x*e^(-2*x)
	find value of f'(0.35) using Richardson Extrapolation Differentiation CDD (central divided difference)
	with h=0.25 and h=0.125

*/

#include<iostream>
#include<cmath>
#define e 2.71828
using namespace std;

float f(float x)
{
	return (5*x*pow(e,(-2*x)));
}

int main()
{
	float h1,h2;
	h1=0.25;
	h2=0.125;
	
	float x;
	cout<<"\nEnter value of x to find differentiation : ";
	cin>>x;
	
	float AV1,AV2,TV;
	
	AV1=(f(x+h1)-f(x-h1))/(2*h1);
	AV2=(f(x+h2)-f(x-h2))/(2*h2);
	
	TV=AV2+(AV2-AV1)/3;       //  TV = True Value = (Value with h=h/2) + (value with h=h/2)-(value with h)
	                          //                                        -----------------------------------
	                          //                                                       3
	cout<<"\nAV1 : "<<AV1;
	cout<<"\nAV2 : "<<AV2;
	cout<<"\nTV  : "<<TV;	
return 0;
}

/*
output


Enter value of x to find differentiation : 0.35

AV1 : 0.988436
AV2 : 0.804715
TV  : 0.743474

*/
