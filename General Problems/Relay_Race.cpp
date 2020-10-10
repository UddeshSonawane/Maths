/* RELAY RACE PROBLEM 

solution by Uddesh
*/

#include<iostream>
using namespace std;

int main()
{
	int n;
	/*cout<<"\nEnter cells in the game : ";    // if we take input from user
	cin>>n;
	float mat[n][n];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"\nEnter value of cell ("<<i<<","<<j<<") : ";
			cin>>mat[i][j];		
		}
	}*/

/*//test case 1
	n=1;
	float mat[n][n]={5};
	int flag[n][n]={0};  // to track positions*/
/*//test case 2
	n=2;
	float mat[n][n]={{11,14},{16,12}};
	int flag[n][n]={{0,0},{0,0}};  // to track positions*/
//test case 3
	n=3;
	float mat[n][n]={{25,16,25},{12,18,19},{11,13,8}};
	int flag[n][n]={{0,0,0},{0,0,0},{0,0,0}}; // to track positions
	
	cout<<"\n** MATRIX BOARD **\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<mat[i][j]<<"\t";		
		}
		cout<<"\n";
	}
	
	int i=0,j=0;
	float sum=mat[i][j];
	flag[i][j]=1;
	
	while(i!=n && j!=n)  // for one who starts first
	{
		//cout<<"\n("<<i<<","<<j<<") --> ";
		if(mat[i+1][j]>mat[i][j+1] && i+1<n && j+1<n)
		{
			sum=sum+mat[i+1][j];
			i=i+1;
			j=j;
			flag[i][j]=1;
			//cout<<"loop 1";
		}
		else if(mat[i+1][j]<mat[i][j+1] && i+1<n && j+1<n)
		{
			sum=sum+mat[i][j+1];
			i=i;
			j=j+1;
			flag[i][j]=1;
			//cout<<"loop 2";
		}
		else if(i+1>=n && j<n)
		{
			sum=sum+mat[i][j+1];
			i=i;
			j=j+1;
			flag[i][j]=1;
			//cout<<"loop 3";
		}
		else if(i<n && j+1>=n)
		{
			sum=sum+mat[i+1][j];
			i=i+1;
			j=j;
			flag[i][j]=1;
			//cout<<"loop 4";
		}
	} // round of first completed -------------------------------------------------
	
	i=n-1;
	j=n-1;
	
	while(i!=0 && j!=0)  // for one who started secondly
	{
		if(mat[i-1][j]>mat[i][j-1] && i-1>=0 && j-1>=0)
		{
			//cout<<"\nloop 1";
			if(flag[i-1][j]==0)
			{
				sum=sum+mat[i-1][j];
				i=i-1;
				j=j;
				flag[i][j]=2;
   				//cout<<"\nloop 11";
			}
			else
			{
				sum=sum+mat[i][j-1];
				i=i;
				j=j-1;
				flag[i][j]=2;
				//cout<<"\nloop 12";
			}
			
		}
		else if(mat[i-1][j]<mat[i][j-1] && i-1>=0 && j-1>=0)
		{
		//cout<<"\nloop 2";
			if(flag[i][j-1]!=1)
			{
				sum=sum+mat[i][j-1];
				i=i;
				j=j-1;
				flag[i][j]=2;
				//cout<<"\nloop 21";
			}
			else
			{
				sum=sum+mat[i-1][j];
				i=i-1;
				j=j;
				flag[i][j]=2;
				//cout<<"\nloop 22";
			}
		}
		else if(i-1<0 && j>=0)
		{
			sum=sum+mat[i][j-1];
			i=i;
			j=j-1;
			flag[i][j]=2;
			//cout<<"\nloop 3";
		}
		else if(i>=0 && j-1<0)
		{
			sum=sum+mat[i-1][j];
			i=i-1;
			j=j;
			flag[i][j]=2;
			//cout<<"\nloop 4";
		}	
	} // round of second completed ------------------------------------------------
	
	cout<<"\n** PATHS FOLLOWED **\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<flag[i][j]<<"\t";		
		}
		cout<<"\n";
	}
	cout<<"\n1 denotes the path followed by first player while\n2 denotes the path followed by second player";

	cout<<"\n\nMaximum Possible Score : "<<sum<<"\n";
	
return 0;
}

/*
OUTPUT

case 1

** MATRIX BOARD **
5	

** PATHS FOLLOWED **
1	

1 denotes the path followed by first player while
2 denotes the path followed by second player

Maximum Possible Score : 5

------------------------------

case 2

** MATRIX BOARD **
11	14	
16	12	

** PATHS FOLLOWED **
1	2	
1	1	

1 denotes the path followed by first player while
2 denotes the path followed by second player

Maximum Possible Score : 53

------------------------------

case 3

** MATRIX BOARD **
25	16	25	
12	18	19	
11	13	8	

** PATHS FOLLOWED **
1	1	1	
2	2	1	
0	2	1	

1 denotes the path followed by first player while
2 denotes the path followed by second player

Maximum Possible Score : 136



*/
