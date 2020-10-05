/*
Finiq assignment problem: solve the integral using Trapezoidal method of Integration

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
	cout<<"\nTrapezoidal Integration";
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
	
	float t1, t2, ft1, ft2, area=0;
	t1=a;
	t2=a+dx;
	
	for(int i=0;i<n;i++)
	{
		ft1=f(t1);
		ft2=f(t2);
		
		//cout<<"\nt1 = "<<t1<<" ft1 = "<<ft1;
		//cout<<"\nt2 = "<<t2<<" ft2 = "<<ft2;
		
		area=area+((ft1+ft2)/2)*dx;
		
		//cout<<"\nArea of this section = "<<((ft1+ft2)/2)*dx;
		//cout<<"\nTotal Area = "<<area;
		t1=t2;
		t2=t2+dx;
		//cout<<"\n-------------------------";
	}
	
	cout<<"\nArea under curve : "<<area;

return 0;
}

/*
Output

iant@iant-System-Product-Name:~$ g++ trapezoidal.cpp
iant@iant-System-Product-Name:~$ ./a.out

Trapezoidal Integration
Enter upper limit : 5

Enter Lower limit : 0

Enter total number of partitions : 1

Width of one interval : 5
Area under curve : 77.5iant@iant-System-Product-Name:~$ ./a.out

Trapezoidal Integration
Enter upper limit : 5

Enter Lower limit : 0

Enter total number of partitions : 3

Width of one interval : 1.66667
Area under curve : 58.9815iant@iant-System-Product-Name:~$ ./a.out

Trapezoidal Integration
Enter upper limit : 5

Enter Lower limit : 0

Enter total number of partitions : 5

Width of one interval : 1
Area under curve : 57.5iant@iant-System-Product-Name:~$ ./a.out

Trapezoidal Integration
Enter upper limit : 5

Enter Lower limit : 0

Enter total number of partitions : 10

Width of one interval : 0.5
Area under curve : 56.875iant@iant-System-Product-Name:~$ ./a.out

Trapezoidal Integration
Enter upper limit : 5

Enter Lower limit : 0

Enter total number of partitions : 50

Width of one interval : 0.1
Area under curve : 56.675   

*/
