/*RNG (Random Number Generator) CLCG (Combined Linear Congruential Generator)

by Uddesh



*/

#include<iostream>
#include<cmath>
using namespace std;

int power(int j)
{
	int num=1;
	for(int i=1;i<j;i++)
	{
		num=num*(-1);
	}
	return num;
}

int main()
{
	cout<<"\nCLCG (Combned Linear Congruential Generator)";
	
	int n;
	cout<<"\nEnter total random numbers to generate : ";
	cin>>n;
	
	int k;
	cout<<"\nEnter total number of LCGs participating : ";
	cin>>k;
	
	int m[k];  //modulus
	int a[k];  //multiplier
	int c[k];  //increment by     (if c=0 : generator is called as Multiplicative CG)
	int x0[k]; //seed or starting value
	
	
	for(int i=0;i<k;i++)
	{
		cout<<"\nEnter the following details for "<<i+1<<" LCG";
		
		cout<<"\nEnter starting value : ";
		cin>>x0[i];
		
		cout<<"\nEnter modulus value (greater than 0): ";
		cin>>m[i];
		
		cout<<"\nEnter multipler value (0 < a < m): ";
		cin>>a[i];
		
		cout<<"\nEnter increment value (0 <= x0 <m): ";
		cin>>c[i];			
	}
	
	int x[k][n];
	cout<<"\n";
	for(int p=0;p<k;p++)
	{
		for(int q=0;q<n;q++)
		{
			x[p][q]=((a[p]*x0[p])+c[p])%m[p];
			cout<<x[p][q]<<"\t";
			x0[p]=x[p][q];
		}
		cout<<"\n";	
	}
	
	
	float clcg_arr[n];      // calculation of Combined LCG
	int temp, power_val, temp2;
	float r[n];             //array to stored random numbers uniformly dstributed between 0 and 1
	int mod=m[0];
	for(int i=0;i<n;i++)
	{
		temp=0;
		for(int j=1;j<=k;j++)
		{
		
			power_val=power(j);	
			//cout<<"\n * "<<power_val;
			temp=temp+(power_val*x[j-1][i]);
			//cout<<"\t"<<(power_val*x[j-1][i]);
		}
		//cout<<"\n -- "<<temp;

		clcg_arr[i]=temp%(mod-1);
		//cout<<" -- "<<clcg_arr[i];		

		temp2=clcg_arr[i];    
		if(temp2>0)  
		{
			r[i]=float(temp2)/float(mod);       // int float casting
		}
		else if(temp2<0)
		{
			r[i]=(float(temp2)/float(mod))+1;   //int float casting
		}
		else if(temp2==0)
		{
			r[i]=float(mod-1)/float(mod);   //int float casting
		}
		
		//cout<<" -- "<<r[i];
	}
	
	int choice;
	do
	{
		cout<<"\n\nWhat do you want to do?";
		cout<<"\n1] Print all numbers\n2] Print particular number\n3] Random numbers between 0 & 1\n0] Exit";
		cin>>choice;
		switch(choice)
		{
			case 1:
					cout<<"\n";
					for(int i=0;i<n;i++)
					{
						cout<<clcg_arr[i]<<"\t";
					}
				break;
				
			case 2:
					cout<<"\n";
					int loc;
					cout<<"\nEnter location : ";
					cin>>loc;
					cout<<clcg_arr[loc-1];
				break;
				
			case 3:
					for(int i=0;i<n;i++)
					{
						cout<<r[i]<<"\t";
					}
				break;
				
			case 0:
				break;
			
			default:
					cout<<"\n";
					cout<<"\nEnter valid option";
				break;
		}
		
	}while(choice!=0);
return 0;
}

/*
OUTPUT


CLCG (Combned Linear Congruential Generator)
Enter total random numbers to generate : 10

Enter total number of LCGs participating : 4

Enter the following details for 1 LCG
Enter starting value : 12

Enter modulus value (greater than 0): 11

Enter multipler value (0 < a < m): 10

Enter increment value (0 <= x0 <m): 9

Enter the following details for 2 LCG
Enter starting value : 27

Enter modulus value (greater than 0): 25

Enter multipler value (0 < a < m): 23

Enter increment value (0 <= x0 <m): 22

Enter the following details for 3 LCG
Enter starting value : 9

Enter modulus value (greater than 0): 7

Enter multipler value (0 < a < m): 5

Enter increment value (0 <= x0 <m): 3

Enter the following details for 4 LCG
Enter starting value : 54

Enter modulus value (greater than 0): 40

Enter multipler value (0 < a < m): 23

Enter increment value (0 <= x0 <m): 16

8	1	8	1	8	1	8	1	8	1	
18	11	0	22	3	16	15	17	13	21	
6	5	0	3	4	2	6	5	0	3	
18	30	26	14	18	30	26	14	18	30	


What do you want to do?
1] Print all numbers
2] Print particular number
3] Random numbers between 0 & 1
0] Exit1

-2	-5	-8	-2	-9	-3	-7	-5	-3	-7	

What do you want to do?
1] Print all numbers
2] Print particular number
3] Random numbers between 0 & 1
0] Exit2


Enter location : 6
-3

What do you want to do?
1] Print all numbers
2] Print particular number
3] Random numbers between 0 & 1
0] Exit3
0.818182	0.545455	0.272727	0.818182	0.181818	0.727273	0.363636	0.545455	0.727273	0.363636	

What do you want to do?
1] Print all numbers
2] Print particular number
3] Random numbers between 0 & 1
0] Exit0



*/
