/*
Derivative using central difference formula (reference method : stirling central interpolation)

year   population in thpusands
1891   46
1901   66
1911   81
1921   93
1931   101

this method gives the value of differentiation at midle observation
here at 1911
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
	
	float h;
	h=arr[1]-arr[0];
	
	float temp=0;

	for(int i=1,j=n/2;i<n;i=i+2)
	{	
		temp=temp+((diff[j][i]+diff[j-1][i])/2)/fact(i);
		j--;	
	}
	
	temp=temp/h;
	
	cout<<"\nDifferentiation at x="<<arr[n/2]<<" --> "<<temp;
	
return 0;
}
