/*
Wichmann Hill Random Number Generator  : proposed by Brian Wichmann and David Hill

by Uddesh

here we need three LCG with specific prime moduli as 30269,30307,30323
seed for all may be any non zero value (between 1 and 30000).

here we take multipliers 171,172,173

x<n+1> = (a*x<n> + c)mod m
*/


#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	cout<<"\nEnter random numbers required : ";
	cin>>n;
	
	int s1,s2,s3;  // seed
	s1=458;
	s2=896;
	s3=237;
	
	int a1,a2,a3;  // multipliers
	a1=171;
	a2=172;
	a3=173;
	
	int c1,c2,c3;  // incrementors
	c1=123;
	c2=124;
	c3=125;
	
	int m1,m2,m3;  // prime moduli
	m1=30269;
	m2=30307;
	m3=30323;
	
	float temp,temp1,temp2,temp3;
	float rn[n];
	float need;  // required if needed
	
	for(int i=0;i<n;i++)
	{
		temp1=((a1*s1)+c1)%m1;
		temp2=((a2*s2)+c2)%m2;
		temp3=((a3*s3)+c3)%m3;
		
		s1=temp1;
		s2=temp2;
		s3=temp3;
		
		temp1=float(temp1/m1);
		temp2=float(temp2/m2);
		temp3=float(temp3/m3);
		
		temp=temp1+temp2+temp3;
		//cout<<"\n"<<temp;
		
		if(temp>1)
		{
			need=floor(temp);
			temp=temp-need;
		}
		
		rn[i]=temp;	
	}
	
	cout<<"\nRANDOM NUMBERS -> ";
	for(int i=0;i<n;i++)
	{
		cout<<rn[i]<<"  ";
	}
		
return 0;
}

/*
output

Enter random numbers required : 30

RANDOM NUMBERS -> 0.0368488  0.115065  0.297029  0.775666  0.451706  
                  0.792262  0.369842  0.164535  0.479236  0.15142  
                  0.677728  0.688556  0.19887  0.573732  0.788407  
                  0.705068  0.995947  0.195649  0.726492  0.308135  
                  0.629907  0.206346  0.931398  0.596182  0.0633328  
                  0.270935  0.853978  0.860776  0.60086  0.498804 

*/
