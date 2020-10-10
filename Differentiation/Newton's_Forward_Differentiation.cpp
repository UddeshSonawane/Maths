/*
Differentiation using Newton's Forward Difference Formula

for ex. we have four datapoints for sine angle and values.

angle  sin(angle)
45     0.7071 -> 7071
50     0.7660 -> 7660
55     0.8192 -> 8192
60     0.8660 -> 8660

NOTE: THIS FORMULA WILL ONLY CALCULATE THE DIFFERENTIATION AT STARTING POINT

Though we are taking sin of angle values, the function sin(x) is unknown to the program.
as per only given 4 points, it's not good to take it granted as the sin(x) curve.

this above point reveal when we find differentiation
here, diff of sin(x) is cos(x)
but when we find value of diff(sin(x)) i.e., cos(x) is not equal to that of result calculated from the program.

this is just only because, the trajectory is unknown.

*/

#include<iostream>
using namespace std;

int cal_one(int x)
{
	if(x%2==0)
		return -1;
	else
		return 1;
}

int main()
{
	//here we will take given values
	int n=4; // n denotes the available datapoints with values
	float arr[4]={45,50,55,60};
	
	float diff[n][n];
	
	diff[0][0]=7071;
	diff[1][0]=7660;
	diff[2][0]=8192;
	diff[3][0]=8660;
	
	for(int j=1;j<n;j++)
	{
		for(int i=0;i<n-j;i++)
		{
			diff[i][j]=diff[i+1][j-1]-diff[i][j-1];
		}
	}
	
	float h;      // diffference between equally spaced intervals
	h=arr[1]-arr[0];
	float d=0;
	
	for(int i=1;i<n;i++)
	{
		d=d+(diff[0][i]*cal_one(i))/float(i);
	}
	
	d=d/h;
	cout<<"\ndifferentiation of at x="<<arr[0]<<" : "<<(d)<<endl;
	
return 0;
}

/*

differentiation of at x=45 : 123.033


-----------------------------------


*/
