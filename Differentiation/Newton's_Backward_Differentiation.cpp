/*

Differentiation using Newton's Backward difference formula

given data values

population 

year   population in thousands
1891   46
1901   66
1911   81
1921   93
1931   101

formula
u = ( x – an ) / h,
          Here an is last term.
          
(dY)r = (Y)r - (Y)(r-1)  // for backward difference table

NOTE : This formula finds the differential value at last point.
*/

#include<iostream>
using namespace std;

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
	
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<i+1;j++)
		{
			diff[i][j]=diff[i][j-1] - diff[i-1][j-1];
		}
	}
	
	float h,val;
	h=arr[1]-arr[0];
	val=0;
	
	for(int i=1;i<n;i++)
	{
		val=val+diff[n-1][i]/i;
	}
	
	cout<<"\nDifferentiation at x="<<arr[n-1]<<" : "<<val/h;
	
return 0;
}

/*
output

Differentiation at x=1931 : 0.491667
*/
