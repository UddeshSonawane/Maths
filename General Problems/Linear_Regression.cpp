/*LINEAR REGRESSION LEAST SQUARE

BY Uddesh

example : x:- hours of sunshine
          y:- ice cream sold

		x | y
	----------------
		2 | 4
		3 | 5
		5 | 7
		7 | 10
		9 | 15
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	/*  If You need to take input fom user
	
	
	int n;
	cout<<"\nEnter total data points ";
	float input_mat[n][2];
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter x"<<i+1;
		cin>>input_mat[i][0];
		cout<<"\nEnter y"<<i+1;
		cin>>input_mat[i][1];
	}*/
	
	
	int n=5; //data points
	float input_mat[5][2]={{2,4},{3,5},{5,7},{7,10},{9,15}};
	
	cout<<"\n****** Matrix *******\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<input_mat[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
	float x,y,xx,xy,temp1,temp2;
	float sum_x=0,sum_y=0,sum_xx=0,sum_xy=0;
	
	for(int i=0;i<n;i++)
	{
		temp1=input_mat[i][0];
		sum_x=sum_x+temp1;
		sum_xx=sum_xx+(temp1*temp1);
		temp2=input_mat[i][1];
		sum_y=sum_y+temp2;
		sum_xy=sum_xy+(temp1*temp2);	
	}
	
	float m,b;  //m -> slope,  b->Y_intercept
	
	m=((n*sum_xy)-(sum_x*sum_y))/((n*sum_xx)-(sum_x*sum_x));
	
	b=(sum_y-(m*sum_x))/n;
	
	cout<<fixed<<setprecision(3)<<"\ny="<<m<<"x+"<<b;   //<<fixed<<setprecision(3)  -> to round up decimal number till 3 decimal places
	
return 0;
}


/*

****** Matrix *******
2	4	
3	5	
5	7	
7	10	
9	15	

y=1.518x+0.305


*/
