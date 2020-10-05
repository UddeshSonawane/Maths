/* Simposon's 1/3 rd Rule     by Uddesh       

lim a->b f(x)dx = (b-a)/6[f(a)+4*f((a+b)/2)+f(b)]


here f(x)=5x+x^2                 (answer given by this method is not exact nor nearby to exact here)

*/

#include<iostream>
using namespace std;

float pow(float num)
{
	float val=1;
	for(int i=0;i<2;i++)
	{
		val=val*num;
	}
	return val;
}

float f(float num)
{
	float val;
	val=5*num+pow(num);
	return val;
}

int main()
{
	float lowerlim, upperlim;
	int parts;
	
	cout<<"\n--- for f(x)=5x+x^2  ---\n";
	
	cout<<"\nEnter lower limit : ";
	cin>>lowerlim;
	
	cout<<"\nEnter upper limit : ";
	cin>>upperlim;
	
	one:
	cout<<"\nEnter number of partitions to be done : ";
	cin>>parts;
	try{
		if(parts%2!=0)
		{
			throw parts;
		}
	}
	catch(int)
	{
		cout<<"\nEven number of partitions required";
		goto one;
	}
	
	float width,sum=0,temp,temp2,part_area;
	
	width=(upperlim-lowerlim)/parts;
	temp=width/3;
	for(float i=lowerlim,j=lowerlim+width,k=1;i<upperlim;i=i+width,j=j+width,k++)
	{
		temp2=(i+j)/2;
		part_area=temp*(f(i)+4*f(temp2)+f(j));
		cout<<"\nArea of part "<<k<<" : "<<part_area;
		sum=sum+part_area;
	}
	
	cout<<"\n----- Area : "<<sum;

return 0;
}


