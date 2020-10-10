/* Newton's Interpolation -> Backward Interpolation

given data values

population 

year   population in thpusands
1891   46
1901   66
1911   81
1921   93
1931   101

we need to find population in 1925

here condition is that, all the given data points should be equidistant.

Formula:

f(a+nh+uh) = f(a+nh) + (u/1!)[(d)f(a+nh)] + ((u(u+1))/2!)[(d^2)f(a+nh)] + ... + ((u(u+1)...(u+n-1))/n!)[(d^n)f(a+nh)]

             ........ f(a+nh) is the final term. here it is f(1931)
             ......... a is assumed first value, here a=1891
             ......... f(a+nh+uh) is nothing but f(1925)
             ......... ------------------------------------------
                       [(d)f(a+nh)] call it as first diff of last value
                       [(d^2)f(a+nh)] call it as second diff of last value
                       .
                       .and so on

This formula is useful when the value of f(x) is required near the end of the table. h is called the interval of
difference
u = ( x – an ) / h,
          Here an is last term.
          
(dY)r = (Y)r - (Y)(r-1)

*/


#include<iostream>
using namespace std;

float cal(float u, int i)
{
	for(float j=1;j<i;j++)
	{
		u=u*(u+j);
	}
return u;
}

int fact(int i)
{
	int factorial=1;
	while(i!=1)
	{
		factorial=factorial*i;
		i--;
	}
return factorial;
}

int main()
{
	//here we will use predefined datapoints and their values
	int n=5; //standard values available
	
	float arr[5]={1891,1901,1911,1921,1931};
	
	float diff[n][n];
	diff[0][0]=46;
	diff[1][0]=66;
	diff[2][0]=81;
	diff[3][0]=93;
	diff[4][0]=101;
	
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<i+1;j++)
		{
			diff[i][j]=diff[i][j-1] - diff[i-1][j-1];
		}
	}
	
	cout<<"\n************************";
	
	for(int i=0;i<n;i++)
	{
		cout<<"\n";
		for(int j=0;j<i+1;j++)
		{
			cout<<diff[i][j]<<"\t";
		}	
	}
	
	
	float test_value;
	cout<<"\nEnter data point to find value at : ";
	cin>>test_value;
	
	//calculation of u
	float u;
	u=(test_value - arr[n-1])/(arr[1]-arr[0]);    
	cout<<"\nu="<<u;
	
	
	float sum=diff[4][0];
	for(int i=1;i<n;i++)
	{
		cout<<"\nsum="<<sum<<"+("<<diff[n-1][i]<<"* ("<<cal(u,i)<<"/"<<fact(i)<<"))";
		sum=sum+(diff[n-1][i]*(cal(u,i)/fact(i)));
		cout<<"\nsum= "<<sum;
	}
	
	
	
	cout<<"\nRequired value : "<<sum;

return 0;
}

/*

************************
46	
66	20	
81	15	-5	
93	12	-3	2	
101	8	-4	-1	-3	
Enter data point to find value at : 1920

u=-1.1
sum=101+(8* (-1.1/1))
sum= 92.2
sum=92.2+(-4* (0.11/2))
sum= 91.98
sum=91.98+(-1* (0.2321/6))
sum= 91.9413
sum=91.9413+(-3* (0.750171/24))
sum= 91.8475
Required value : 91.8475

------------------------------------------


************************
46	
66	20	
81	15	-5	
93	12	-3	2	
101	8	-4	-1	-3	
Enter data point to find value at : 1925

u=-0.6
sum=101+(8* (-0.6/1))
sum= 96.2
sum=96.2+(-4* (-0.24/2))
sum= 96.68
sum=96.68+(-1* (-0.4224/6))
sum= 96.7504
sum=96.7504+(-3* (-1.08878/24))
sum= 96.8865
Required value : 96.8865

*/
