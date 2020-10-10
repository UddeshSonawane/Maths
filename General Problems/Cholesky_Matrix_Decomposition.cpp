/*
CHOLESKY MATRIX DECOMPOSITION

it is a decomposition of a Hermitian, positive definite matrix into the product of a lower triangular matrix and its conjugate transpose

A=LL*


assumption : firstly here we are only dealing with real numbers not with complex numbers
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	cout<<"\nHere we are using predefined 3 by 3 matrix";
	int n=3;
	float A[n][n]={{4,12,-16},{12,37,-43},{-16,-43,98}}; // diagonal elements must be positive
	
	cout<<"\nTo find lower triangular matrix";
	
	float L[n][n],LT[n][n];
	float temp,sum;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			L[i][j]=0;
			LT[i][j]=0;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			temp=0;
			sum=0;
			if(i==j)
			{			
				for(int k=0;k<j;k++)
				{
					temp=L[j][k];
					sum=sum+temp*temp;
				}
				L[i][j]=sqrt(A[i][j]-sum);
			}
			else
			{
				for(int k=0;k<j;k++)
				{
					sum=sum+L[i][k]*L[j][k];
				}
				temp=(A[i][j]-sum)/L[j][j];
				L[i][j]=temp;
			}
			LT[j][i]=L[i][j]; //transpose of L
		}
	}
	
	
	/*
	cout<<"\n*****MATRIX******\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"\t"<<A[i][j];
		}
		cout<<"\n";
	}
	
	cout<<"\n******* Lower Triangular Matrix **********\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"\t"<<L[i][j];
		}
		cout<<"\n";
	}
	
	cout<<"\nCONJUGATE TRANSPOSE OF L\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{	
			cout<<"\t"<<LT[i][j];
		}
		cout<<"\n";
	}*/
	
	cout<<"\n        A\t                    L\t                    L*";
	for(int i=0;i<n;i++)
	{
		cout<<"\n|";
		for(int j=0;j<n;j++)
		{
			cout<<A[i][j]<<"\t";
		}
		if(i==1)
			cout<<"| = |";
		else
			cout<<"|   |";
			
		for(int j=0;j<n;j++)
		{
			cout<<L[i][j]<<"\t";
		}
		if(i==1)
			cout<<"| * |";
		else
			cout<<"|   |";
		for(int j=0;j<n;j++)
		{
			cout<<LT[i][j]<<"\t";
		}
		
		cout<<"|";
	}
	
	
return 0;
}
