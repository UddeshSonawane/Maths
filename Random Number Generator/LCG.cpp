/*RNG (Random Number Generator) LCG (Linear Congruential Generator)

by Uddesh

X(n+1) = (a * X(n) + c) mod m

*/

#include<iostream>
using namespace std;

int main()
{
	cout<<"\nLCG (Linear Congruential Generator)";
	
	int n;
	cout<<"\nEnter total random numbers to generate : ";
	cin>>n;
	
	int m;  //modulus
	int a;  //multiplier
	int c;  //increment by     (if c=0 : generator is called as Multiplicative CG)
	int x0; //seed or starting value
	
	cout<<"\nEnter starting value : ";
	cin>>x0;
	
	cout<<"\nEnter modulus value (greater than 0): ";
	cin>>m;
	
	cout<<"\nEnter multipler value (0 < a < m): ";
	cin>>a;
	
	cout<<"\nEnter increment value (0 <= x0 <m): ";
	cin>>c;
	
	int x;
	cout<<"\n";
	for(int i=0;i<n;i++)
	{
		x=((a*x0)+c)%m;
		cout<<x<<"\t";
		x0=x;
	}
	
return 0;
}
