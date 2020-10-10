/*RNG Lagged Fibonacci  by Uddesh

Sn = ( S<n-j> * S<n-k> )mod m         0<j<k
                                      m= power of 2  (often 2^32 or 2^64)
                                      (j,k) will take only particular values to make period large
                                      some of the pairs are
                                      (7,10),(5,17),(24,55),(65,71),(128,159),......
new term in the sequence depends on any two terms in fibb series as per condition.


* can be anything. either multiplication, adition, or XOR. according to that sign name of the method changes
  it's a general library operator.
  
  if +  -> Additive Lagged Fibonacci Series Generator
  if *  -> Multiplicative Lagged Fibonacci Series Generator
  if XOR  -> Two tap generalised shift generator

here we use * operator

*/

#include<iostream>
using namespace std;

long int power()
{
	long int m=1;
	for(int i=0;i<32;i++)
	{
		m=m*2;
	}
	//cout<<"\n\n"<<m;
	return m;
}

int main()
{
	int tot;  // denotes total random numbers to find
	cout<<"\nEnter total Random Numbers to find : ";
	cin>>tot;
	
	// here by default we are using (j,k) = (7,10)
	int j=7,k=10;
	
	long int fib_series[tot+k];
	
	//----------------------------------------fibonacci series original start
	int temp1,temp2;
	fib_series[0]=temp1=0;
	fib_series[1]=temp2=1;
	
	int temp;
	//cout<<temp1<<"  "<<temp2<<"  ";
	for(int i=2;i<tot+k;i++)
	{
		temp=temp1+temp2;
		fib_series[i]=temp;
		temp1=temp2;
		temp2=temp;
	} //-------------------------------------fib original end
	
	/*
	//to print original fibonacci series
	
	cout<<"\nFIBONACCI SERIES -> ";
	for(int i=0;i<tot+k;i++)
	{
		cout<<fib_series[i]<<"  ";
	}*/
	
	long int result[tot];
	int tp=k-j;
	long int m=power();

	for(int i=0;i<tot;i++)
	{
		result[i]=(fib_series[tp+i] * fib_series[i])%m;
	}
	
	cout<<"\n\nRandom Numbers -> ";
	for(int i=0;i<tot;i++)
	{
		cout<<result[i]<<"  ";
	}	
	
return 0;
}

/*
output

Enter total Random Numbers to find : 30


Random Numbers -> 0  3  5  16  39  105  272  715  1869  4896  
                  12815  33553  87840  229971  602069  1576240  
                  4126647  10803705  28284464  74049691  193864605  
                  507544128  1328767775  3478759201  517575232  
                  2368933795  2294258853  218875472  2657334855  3458161801  
                  
*/
