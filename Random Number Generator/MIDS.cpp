/* Mid square Random Number Generator

by Uddesh

n digit seed  -> sqaure it -> extract middle n digits  -> that will be your RN and new seed
                                  
                  --> if square is not of 2n digit then append remaining zeros to left of that number
                  --> then extract middle n digits

*/

#include<iostream>
#include<string>
using namespace std;

int power(int x)
{
	int val=10;
	if(x==1)   // value less then 1 not possible as n>2
	{
		return val;
	}
	else
	{
		while(x!=1)
		{
			val=val*10;
			x--;
		}
	}
	//cout<<"\nVal="<<val;
return val;
}

int main()
{
	
	int n;  // will specify the digits of random number. n>2 for significance
	cout<<"\n3 for 3 digit number\n4 for 4 digit number\nin the same way\nEnter digits of random number : ";
	cin>>n;
	
	int tot;  //RN to be generated
	cout<<"\nEnter total number of random number to be generated : ";
	cin>>tot;
	
	int seed;
	cout<<"\nEnter "<<n<<" digit seed value or starting value : ";
	cin>>seed;
	
	int RN[n],temp,sub_from_n, temp_n;
	if(n%2==0)
 		sub_from_n=n-(n/2);
	else
		sub_from_n=n-((n+1)/2); // better to consider known value
	
	//cout<<"\nsub_from_n="<<sub_from_n;
	
	RN[0]=seed;
	for(int i=1;i<tot;i++)
	{
		//cout<<"\n"<<i<<"]";
		temp=seed;
		//cout<<"\nseed = "<<seed;
		temp=temp*temp;
		//cout<<"\nseed^2 = "<<temp;
		temp=temp/power(sub_from_n);
		//cout<<"\ntemp = "<<temp;
		temp=temp%power(n);
		//cout<<"\ntemp = "<<temp<<"\n";
		RN[i]=temp;
		seed=temp;
	}

	cout<<"\nRANDOM NUMBERS : ";
	for(int i=0;i<tot;i++)
	{
		cout<<RN[i]<<" ";
	}

return 0;
}

/*

output

3 for 3 digit number
4 for 4 digit number
in the same way
Enter digits of random number : 4

Enter total number of random number to be generated : 15

Enter 4 digit seed value or starting value : 4523

RANDOM NUMBERS : 4523 4575 9306 6016 1922 6940 1636 6764 7516 4902 296 876 7673 8749 5450 
---------------------------------------------------------------------------------------

 >< >< >< >< >< >< >< >< ><
 solve this core dump problem
 
 3 for 3 digit number
4 for 4 digit number
in the same way
Enter digits of random number : 4

Enter total number of random number to be generated : 20

Enter 4 digit seed value or starting value : 4523

1]
seed = 4523
seed^2 = 20457529
temp = 204575
temp = 4575

2]
seed = 4575
seed^2 = 20930625
temp = 209306
temp = 9306

3]
seed = 9306
seed^2 = 86601636
temp = 866016
temp = 6016

4]
seed = 6016
seed^2 = 36192256
temp = 361922
temp = 1922

5]
seed = 1922
seed^2 = 3694084
temp = 36940
temp = 6940

6]
seed = 6940
seed^2 = 48163600
temp = 481636
temp = 1636

7]
seed = 1636
seed^2 = 2676496
temp = 26764
temp = 6764

8]
seed = 6764
seed^2 = 45751696
temp = 457516
temp = 7516

9]
seed = 7516
seed^2 = 56490256
temp = 564902
temp = 4902

10]
seed = 4902
seed^2 = 24029604
temp = 240296
temp = 296

11]
seed = 296
seed^2 = 87616
temp = 876
temp = 876

12]
seed = 876
seed^2 = 767376
temp = 7673
temp = 7673

13]
seed = 7673
seed^2 = 58874929
temp = 588749
temp = 8749

14]
seed = 8749
seed^2 = 76545001
temp = 765450
temp = 5450

15]
seed = 5450
seed^2 = 29702500
temp = 297025
temp = 7025

16]
seed = 7025
seed^2 = 49350625
Floating point exception (core dumped)

*/
