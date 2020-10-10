/* LFSR Random Number Generator

(LFSR -> LINEAR FEEDBACK SHIFT REGISTER)

*/

#include<iostream>
#include<cmath>
using namespace std;

int XOR(int a, int b)
{
	if(a==b)
		return 0;
	else
		return 1;
}

int main()
{
	int n,a,b,temp,flag1,flag2;
	cout<<"\nEnter index (no of bits) : ";
	cin>>n;
	flag1=0;
	flag2=0;
	int seed[n];
	int seed_val=0;
	cout<<"\nEnter n bit binary seed number bit by bit starting from MSB : ";
	//method will fail for seed values with 2^n as there we get only single bit 1
	//as here xor used
	// and also fails for all bits 1
	//                    all bits 0
	//                    alternate 1 and 0
	for(int i=0;i<n;i++)
	{
		cout<<"\nbit "<<i+1<<" : ";
		cin>>temp;
		if(temp==1)
		{
			if(flag1==0)
			{
				a=i;
				flag1=1;
			}
			else if(flag2==0)
			{
				b=i;
				flag2=1;
			}
			seed_val=seed_val+pow(2,n-1-i);
		}
		seed[i]=temp;
	}
	

	cout<<"\nSeed value : ";
	for(int i=0;i<n;i++)
	{
		cout<<seed[i];
	}
	cout<<" ---- "<<seed_val;
	
	cout<<"\na="<<a<<" b="<<b<<endl;
	
	int x;
	x=pow(2,n)-1;
	int rnd[x];
	rnd[0]=seed_val;
	int num,j=1;
	do
	{
		num=0;
		for(int i=0;i<n-1;i++)
		{
			seed[i]=seed[i+1];
			if(seed[i]==1)
			{
				num=num+pow(2,n-1-i);
			}
		}
		seed[n-1]=XOR(seed[a],seed[b]);
		for(int i=0;i<n;i++)
		{
			cout<<seed[i];
		}
		if(seed[n-1]==1)
		{
			num=num+1;    //since 2^0=1
		}
		rnd[j]=num;
		cout<<" -> "<<num<<endl;
		j++;
	}while(num!=seed_val);
	
	int numbers=j;
	cout<<"\nTotal numbers : "<<numbers;
return 0;
}

/*
output

Enter index (no of bits) : 5

Enter n bit binary seed number bit by bit starting from MSB : 
bit 1 : 1

bit 2 : 1

bit 3 : 0

bit 4 : 0

bit 5 : 0

Seed value : 11000 ---- 24
a=0 b=1
10001 -> 17
00010 -> 2
00100 -> 4
01001 -> 9
10011 -> 19
00110 -> 6
01101 -> 13
11010 -> 26
10101 -> 21
01011 -> 11
10111 -> 23
01111 -> 15
11110 -> 30
11100 -> 28
11000 -> 24

Total numbers : 16

-----------------------------------------------------------

faulty output

Enter index (no of bits) : 5

Enter n bit binary seed number bit by bit starting from MSB : 
bit 1 : 1

bit 2 : 0

bit 3 : 1

bit 4 : 0

bit 5 : 1 

Seed value : 10101 ---- 21
a=0 b=2
01010 -> 10
10100 -> 20
01000 -> 8
10001 -> 17
00010 -> 2
00101 -> 5
01010 -> 10
10100 -> 20
01000 -> 8
10001 -> 17
00010 -> 2
00101 -> 5
01010 -> 10
10100 -> 20
01000 -> 8
10001 -> 17
00010 -> 2
00101 -> 5
01010 -> 10
10100 -> 20
01000 -> 8
10001 -> 17
00010 -> 2
00101 -> 5
01010 -> 10
10100 -> 20
01000 -> 8
10001 -> 17
00010 -> 2
00101 -> 5
01010 -> 10
10100 -> 20
01000 -> 8
80001 -> 1
01010 -> 10
101001 -> 17
0100170 -> 0
1001701 -> 1
017010 -> 2
170101 -> 5
01010 -> 10
10100 -> 20
01000 -> 8
10001 -> 17
00010 -> 2
00101 -> 5
01010 -> 10
10100 -> 20
01000 -> 8
10001 -> 17
00010 -> 2
00101 -> 5
01010 -> 10
10100 -> 20
01000 -> 8
10000121 -> 133
00001210 -> 10
00012101 -> 21

Total numbers : 59

*/
