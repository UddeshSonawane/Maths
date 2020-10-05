/*
Finiq assignment problem: solve the integral using Reimann Sum method of Integration

by Uddesh

here function f() will need to modify each time for every differnt function
*/

#include<iostream>
using namespace std;

float f(float x)
{
	float y;
	y=x*x+3;
	return y;
}

int main()
{
	cout<<"\nReimann Sum";
	float a,b,n;
	
	cout<<"\nEnter upper limit : ";
	cin>>b;
	
	cout<<"\nEnter Lower limit : ";
	cin>>a;
	
	cout<<"\nEnter total number of partitions : ";
	cin>>n;
	
	float dx;
	dx=(b-a)/n;
	cout<<"\nWidth of one interval : "<<dx;
	
	int choice;
	do
	{
		cout<<"\nChoose your way\n1) Left\n2) Right\n3) Midpoint\n0)Exit\n\t --> ";
		cin>>choice;
		float t1, ft1, area=0;
	
		switch(choice)
		{
			case 1:
				cout<<"\nLeft Reimann Sum";
				t1=a;
				for(int i=0;i<n;i++)
				{
					ft1=f(t1);
					//cout<<"\nt1 = "<<t1<<" ft1 = "<<ft1;
					area=area+ft1*dx;
					//cout<<"\nArea of this section = "<<ft1*dx;
					//cout<<"\nTotal Area = "<<area;
					//cout<<"\n-----------------------------";
					t1=t1+dx;	
				}
				cout<<"\nArea under curve : "<<area;
				break;
			
			case 2:
				cout<<"\nRight Reimann Sum";
				t1=a+dx;
				for(int i=0;i<n;i++)
				{
					ft1=f(t1);
					//cout<<"\nt1 = "<<t1<<" ft1 = "<<ft1;
					area=area+ft1*dx;
					//cout<<"\nArea of this section = "<<ft1*dx;
					//cout<<"\nTotal Area = "<<area;
					//cout<<"\n-----------------------------";
					t1=t1+dx;
				}
				cout<<"\nArea under curve : "<<area;
				break;
			
			case 3:
				cout<<"\nMidpoint Reimann Sum";
				t1=a+(dx/2);
				for(int i=0;i<n;i++)
				{
					ft1=f(t1);
					//cout<<"\nt1 = "<<t1<<" ft1 = "<<ft1;
					area=area+ft1*dx;
					//cout<<"\nArea of this section = "<<ft1*dx;
					//cout<<"\nTotal Area = "<<area;
					//cout<<"\n-----------------------------";
					t1=t1+dx;
				}
				cout<<"\nArea under curve : "<<area;
				break;
			
			case 0:
				cout<<"\nProcess treminated";
				break;
			
			default:
				cout<<"\nChoose appropriate option";
				break;
		}
	}while(choice!=0);
	
return 0;
}

/*
Output

Reimann Sum
Enter upper limit : 5

Enter Lower limit : 0

Enter total number of partitions : 20

Width of one interval : 0.25
Choose your way
1) Left
2) Right
3) Midpoint
0)Exit
	 --> 1

Left Reimann Sum
Area under curve : 53.5938
Choose your way
1) Left
2) Right
3) Midpoint
0)Exit
	 --> 2

Right Reimann Sum
Area under curve : 59.8438
Choose your way
1) Left
2) Right
3) Midpoint
0)Exit
	 --> 3

Midpoint Reimann Sum
Area under curve : 56.6406
Choose your way
1) Left
2) Right
3) Midpoint
0)Exit
	 --> 0

Process treminated

*/
