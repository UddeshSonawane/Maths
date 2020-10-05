/* Boole's Rule of integration       program by Uddesh



I= lim a->b f(x)dx = ((2*h)/45) * (7*f(a)+32*f(x1)+12*f(x2)+32*f(x3)+7*f(b))

       where
              h=((b-a)/4)        xi=a+i*h

Note : Here the whole region is divided into 4 parts. Therefore it is divided by 4



for this problem f(x)=5x+x^2;


*/

#include<iostream>
using namespace std;

float pow(float temp)
{
	float val=1;
	for(int i=0;i<2;i++)
	{
		val=val*temp;
	}
	return val;
}

float fx(float temp)
{
	float val;
	val=5*temp+pow(temp);
	return val;
}


int main()
{
	cout<<"\n------ f(x)=5x+x^2 -------";

	float upperlim, lowerlim;               // a and b in above formula
	cout<<"\nEnter upper limit : ";
	cin>>upperlim;
	cout<<"\nEnter lower lim : ";
	cin>>lowerlim;
	
	cout<<"\n----- lim  "<<lowerlim<<" -> "<<upperlim;
	
	float width;           // h in above formula
	width=(upperlim-lowerlim)/4;
	cout<<"\n****** width : "<<width;
	
	float f_val[5],temp1,temp2;
	
	for(int i=0;i<=4;i++)
	{
		temp1=lowerlim+(i*width);
		temp2=fx(temp1);
		f_val[i]=temp2;
		
		cout<<"\nf("<<temp1<<") = "<<temp2;
	}

	cout<<"\nValue of integration is : ";
	
	float sum=0;
	sum=((2*width)/45) * ( 7*f_val[0]+32*f_val[1]+12*f_val[2]+32*f_val[3]+7*f_val[4] );
	
	cout<<sum;
	
return 0;

}


/*


------ f(x)=5x+x^2 -------
Enter upper limit : 2

Enter lower lim : 0

----- lim  0 -> 2
****** width : 0.5
f(0) = 0
f(0.5) = 2.75
f(1) = 6
f(1.5) = 9.75
f(2) = 14
Value of integration is : 12.6667

*/
