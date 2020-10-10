/* Newton's Interpolation -> Forward Interpolation

Here you are given with some datapoints and some values associated with it.

for ex. we have four datapoints for sine angle and values.

angle  sin(angle)
45     0.7071 -> 7071
50     0.7660 -> 7660
55     0.8192 -> 8192
60     0.8660 -> 8660

Though we are taking sin of angle values, the function sin(x) is unknown to the program.
as per only given 4 points, it's not good to take it granted as the sin(x) curve.


here d is used for notation of delta which is for difference used in derivation

f(a+hu) = f(a)+udf(a)+((u(u-1))/2!)*d^2f(a)+ .......+ ((u(u-1)(u-2)...(u-n-1))/n!)d^nf(a)

*/


#include<iostream>
using namespace std;

float cal(float u, int i)
{
	float val=u;
	for(int j=1;j<i;j++)
	{
		val=val*(u-j);
	}
	return val;
}

int fact(int y)
{
	int x=1;
	while(y!=0)
	{
		x=x*y;
		y--;
	}
	return x;
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
	
	cout<<"\n*********** diff table  *********\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			cout<<diff[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
	int x;
	cout<<"\nEnter value to find the answer : ";
	cin>>x;
	
	float u,sum;
	sum=diff[0][0];
	u=(x-arr[0])/(arr[1]-arr[0]);
	cout<<"\nu="<<u;
	
	for(int i=1;i<n;i++)
	{
		cout<<"\nsum = "<<sum<<" + "<<"("<<diff[0][i]<<"*"<<cal(u,i)<<") / "<<fact(i);
		sum=sum+(diff[0][i]*cal(u,i))/fact(i);
	}
	
	cout<<"\nAnswer : "<<sum/10000;

return 0;
}

/*
output

*********** diff table  *********
7071	589	-57	-7	
7660	532	-64	
8192	468	
8660	

Enter value to find the answer : 52

u=1.4
sum = 7071 + (589*1.4) / 1
sum = 7895.6 + (-57*0.56) / 2
sum = 7879.64 + (-7*-0.336) / 6
Answer : 0.788003

*/
