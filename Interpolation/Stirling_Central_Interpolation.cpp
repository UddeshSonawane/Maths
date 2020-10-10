/*

Stirling Central INterpolation


year   population in thpusands
1891   46
1901   66
1911   81
1921   93
1931   101

we need to find population in 1910
*/

#include<iostream>
using namespace std;

float fact(int x)
{
	int val=1;
	for(int i=0;i<x;i++)
	{
		val=val*x;
		x--;
	}
	return float(val);
}

float cal_one(float u, int j)   // following two finctions are same with just a difference of 
{                               //  starting value of for loop
	float val=1;
	for(int i=0;i<=j;i++)
	{
		val=val*((u*u)-(i*i));
	}
	return val;
}

float cal_two(float u, int j)
{
	float val=1;
	for(int i=1;i<=j;i++)
	{
		val=val*((u*u)-(i*i));
	}
	return val;
}

int main()
{
	//here we will use predefined datapoints and their values
	int n=5; //standard values available
	
	float arr[5]={1891,1901,1911,1921,1931};
	
	float diff[n][n];
	diff[0][0]=46;
	diff[1][0]=66;
	diff[2][0]=81;
	diff[3][0]=93;
	diff[4][0]=101;
	
	for(int j=1;j<n;j++)
	{
		for(int i=0;i<n-j;i++)
		{
			diff[i][j]=diff[i+1][j-1]-diff[i][j-1];
		}
	}
	/*
	cout<<"\n*********** diff table  *********\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			cout<<diff[i][j]<<"\t";
		}
		cout<<"\n";
	}*/
	
	float test_value;
	cout<<"\nEnter data point to find value at : ";
	cin>>test_value;
	
	//calculation of u
	float u;
	u=(test_value - arr[n/2])/(arr[1]-arr[0]);    
	//cout<<"\nu="<<u;
	
	float sum=diff[n/2][0];
	float temp=0,temp1,temp2;
	int k1,k2;
	k2=0;
	k1=0;
	for(int i=1,j=n/2;i<n;i++)
	{
		if(i%2==0)
		{
			temp2=temp2+((diff[j][i]*cal_one(u,k1))/fact(i));
			k1++;
		}
		else
		{
			
			if(i==1)
				temp1=temp1+((diff[j][i]+diff[j-1][i])/2)/fact(i);
			else
				temp1=temp1+(((diff[j][i]+diff[j-1][i])/2)*cal_two(u,k2))/fact(i);
			k2++;
			j--;
		}
	}
	
	temp1=temp1*u;
	
	sum=sum+temp1+temp2;
	
	cout<<"\nValue at x="<<test_value<<" -->  "<<sum;
	
return 0;
}

/*

output

Enter data point to find value at : 1915

Value at x=1915 -->  86.1656
-----------------------------------------------------

Enter data point to find value at : 1911

Value at x=1911 -->  81
----------------------------------------------------

Enter data point to find value at : 1910

Value at x=1910 -->  79.6457
--------------------------------------------------

Enter data point to find value at : 1908

Value at x=1908 -->  76.8582
----------------------------------------------------

Enter data point to find value at : 1917

Value at x=1917 -->  88.5856

*/

