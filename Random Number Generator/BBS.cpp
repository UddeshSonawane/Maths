/*
BLUM BLUM SHUB Random Number Generator
by Uddesh

X(n+1)=X(n)^2 mod M

			M = p * q      (p & q are large primes)
						(p & q both are congruent to 3mod 4
							means when p or q get divided by 4 it will give remainder 3
						and GCD of ( (p-3)/2, (q-3)/2 ) should be small to make cycle period large 
						                                
						                                this point is not cleared as how small it should be)
			
			X0 = seed/start value   ( X0 % p != 0
							      X0 % q != 0 
								 X0 !=1
								 X0 !=0 )
									  
		
		
	to fetch directly ith element
	
	X(i)=[X0^((2^i)*mod lambda(M))] mod M
						
						lambda -> Carmichoel function
						lambda(M) = lambda(p*q) = LCM(p-1,q-1).

From "equals" to "congruent"

Since we understand modular division, what exactly does "15 3 (mod 4)" mean?
For starters, we read this as "15 is congruent to 3 mod 4." 
Initially, the order seems a little confusing. We know that 15 mod 4 = 3,
so what's the difference? 
The point of congruency is the following: If we say that a b (mod n),
this means that in the scope of "mod n", a and b are equivalent.
How is this so? Consider an extension on the example above. We already know that 15 3 (mod 4).
We can also say that 15 19 (mod 4), since 15 mod 4 gives the same result as 19 mod 4, namely 3.
So 15 and 19 are congruent modulo 4 because both give the same remainder when divided by 4.
Note that this is starkly different from "equals", since 15 mod 4 certainly does not "equal" 19.
Formally, a b (mod n) if n divides (a - b). Also, a b (mod n) if and only if a mod n = b mod n.
From the original example, 15 3 (mod 4) since 4 | (15-3), and we see that 15 mod 4 = 3 mod 4 = 3.


Why is this useful?

Without getting into the details,
For example, consider 15 + 18 mod 4. 
Since 15 3 mod 4 and 18 2 mod 4, we expect that 3 + 2 mod 4 should have the same result
as 15 + 18 mod 4. Indeed, 15 + 18 = 33, and 33 mod 4 is 1, just as 3 + 2 = 5, and 5 mod 4 is 1.
This is not just a coincidence - it is the beauty of congruency. 

*/


#include<iostream>
using namespace std;

bool isprime(int x)
{
	int count=0,num=1;
	bool flag=true;
	while(num!=x)
	{
		if(x%num==0)
		{
			count++;
			if(count>1)
			{
				flag=false;
				break;
			}
		}
		num++;
	}
	return flag;
}

int main()
{
	int n;
	cout<<"\nEnter number of random numbers to be generated  : ";
	cin>>n;
	
	int p,q;  // prime numbers
	bool ip;
	cout<<"\nEnter two large prime numbers : ";
	while(1)
	{
		cout<<"\n1st prime number -> ";
		cin>>p;
		if(isprime(p)==true)
		{
			if(p%4==3)
			{
				cout<<"\nNumber accepted";
				break;
			}
			else
			{
				cout<<"\nREJECTED! error->Congruentiality violation\nPlease enter another number";
				continue;
			}
		}
		else
		{
			cout<<"\nREJECTED! error->PRIME NUMBER violation\nPlease enter prime number";
			continue;
		}
	}//end of while
		
	while(1)
	{
		cout<<"\n2nd prime number -> ";
		cin>>q;
		if(isprime(q))
		{
			if(q%4==3)
			{
				cout<<"\nNumber accepted";
				break;
			}
			else
			{
				cout<<"\nREJECTED! error->Congruentiality violation\nPlease enter another number ";
				continue;
			}
		}
		else
		{
			cout<<"\nREJECTED! error->PRIME NUMBER violation\nPlease enter prime number";
			continue;
		}
	}//end of 2nd while	
	
	int mod_value;  // M -> mod that will be used to find RN
	mod_value= p*q; 
	
	cout<<"\nmod value -> "<<mod_value;
	
	int seed_val;
	while(1)
	{
		cout<<"\n*******************\nINSTRUCTIONS";
		cout<<"\nseed value should not be 1 nor 0\nseed value should not be the factor of both prime numbers";
		
		cout<<"\nEnter seed value : ";
		cin>>seed_val;
		if(seed_val%p!=0 && seed_val%q!=0 && seed_val!=0 && seed_val!=1)
		{
			cout<<"\nseed value ACCEPTED!\n";
			break;
		}
		else
		{
			cout<<"\nseed value REJECTED! Please fulfill the conditions\n";
		}	
	}
	
	cout<<"\nYehh! You met all the conditions\n";
	
	int rn[n], temp;
	rn[0]=seed_val;
	for(int i=1;i<n;i++)
	{
		temp=(temp*temp)%mod_value;
		rn[i]=temp;
	}
	
	cout<<"\nRandom Numbers Generated\n";
	for(int i=0;i<n;i++)
	{
		cout<<rn[i]<<"  ";
	}	
	
return 0;
}

/*
output

Enter number of random numbers to be generated  : 6

Enter two large prime numbers : 
1st prime number -> 3

Number accepted
2nd prime number -> 7

Number accepted
mod value -> 21
*******************
INSTRUCTIONS
seed value should not be 1 nor 0
seed value should not be the factor of both prime numbers
Enter seed value : 5 

seed value ACCEPTED!

Yehh! You met all the conditions

Random Numbers Generated
5  -10  16  4  16  4 

*/
