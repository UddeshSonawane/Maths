/*

Romberg Integration

f(x)=5x+x^2

*/

#include<iostream>
#include<cmath>
using namespace std;

float f(float x)
{
	return (5*x+x*x);
}

float h_val(int n, float a, float b)    //a-> lower limit, b->upper limit
{
	float val=1.0;
	for(int i=0;i<n;i++)
		val=val*2;
	return ((b-a)/val);   
}

int power_two(int n)
{
	int val=1;
	if(n==0)
		return 1;
	else
		for(int i=0;i<n;i++)
			val=val*2;
	return val;
}

int power_four(int n)
{
	int val=1;
	for(int i=0;i<n;i++)
		val=val*4;
	return val;
}

int main()
{
	float upperlim,lowerlim;
	cout<<"\nEnter upper limit of integration : ";
	cin>>upperlim;
	cout<<"\nEnter lower limit of integration : ";
	cin>>lowerlim;
	
	label1:
	int n,m;   // note :  Larger the value of m and n, accurate result will be achieved.
	cout<<"\nEnter result betterment index : ";     //one may get unexpected values for small m and n. So try for further values
	cout<<"\nenter 'm' such that m>=1 : ";
	cin>>m;
	cout<<"\nEnter 'n' such that n>=m : ";
	cin>>n;
	
	float r[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			r[i][j]=0;
		}
	} 
	
	float h; //distance between two intervals ...... same as that of in trapezoidal rule
	
	if(n!=0 && m!=0)
	{
		r[0][0]=h_val(1,lowerlim,upperlim)*(f(lowerlim)+f(upperlim));
	}
	else
	{
		cout<<"\nPLEASE CHOOSE BETTERMENT INDES AS PER CONDITIONS";
		goto label1;
	}
	
	float temp_sum,temp_h;
	temp_sum=0;
	int k,pow;                    // pow variable will be reused for nest loop
	for(int i=1;i<n;i++)
	{
		temp_h=h_val(i,lowerlim,upperlim);
		pow=power_two(i-1);
		for(int k=1;k<=pow;k++)
		{
			temp_sum=temp_sum+f(lowerlim+((2*k)-1)*temp_h);
		}
		temp_sum=temp_sum*temp_h;
		r[i][0]=(r[i-1][0]/2.0)+temp_sum;
	}

	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=i && j<m;j++)
		{
			float(pow)=float(power_four(j));
			r[i][j]=r[i][j-1]+(r[i][j-1]-r[i-1][j-1])/(pow-1);
		}
	}
	
	cout<<"\nBETTERMENT TABLE\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			cout<<r[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
	cout<<"\nAnswer : "<<r[n-1][m-1];
return 0;
}

/*


Enter upper limit of integration : 2

Enter lower limit of integration : 0

Enter result betterment index : 
enter 'm' such that m>=1 : 15

Enter 'n' such that n>=m : 15

BETTERMENT TABLE
14	
13	12.6667	
15.75	16.6667	16.9333	
16.5	16.75	16.7556	16.7527	
15.6562	15.375	15.2833	15.26	15.2541	
14.623	14.2786	14.2056	14.1884	14.1842	14.1832	
13.8569	13.6015	13.5563	13.546	13.5435	13.5429	13.5427	
13.364	13.1997	13.1729	13.1668	13.1653	13.1649	13.1648	13.1648	
13.0656	12.9661	12.9505	12.947	12.9461	12.9459	12.9459	12.9459	12.9459	
12.891	12.8329	12.824	12.822	12.8215	12.8214	12.8213	12.8213	12.8213	12.8213	
12.7913	12.758	12.753	12.7519	12.7516	12.7516	12.7515	12.7515	12.7515	12.7515	12.7515	
12.7352	12.7165	12.7137	12.7131	12.7129	12.7129	12.7129	12.7129	12.7129	12.7129	12.7129	12.7129	
12.704	12.6936	12.6921	12.6918	12.6917	12.6917	12.6917	12.6917	12.6917	12.6917	12.6917	12.6917	12.6917	
12.6869	12.6812	12.6804	12.6802	12.6801	12.6801	12.6801	12.6801	12.6801	12.6801	12.6801	12.6801	12.6801	12.6801	
12.6776	12.6745	12.674	12.6739	12.6739	12.6739	12.6739	12.6739	12.6739	12.6739	12.6739	12.6739	12.6739	12.6739	12.6739	

Answer : 12.6739

*/
