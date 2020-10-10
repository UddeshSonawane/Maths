/*
BLACK SCHOLES OPTION PRICING

NOTE: here in the formula of calculating call and put values, we ned to refer the
       Commulative Normal Distribution Tables.
       But as a programming point of view, it will be time consuming to declare and define the whole table
       newly in program. 
       There is no straight function which will give the value directly.
       
       But, since the guassian error function and its complementary function is related
       to the normal commulative distribution function.
       so, we can use the implemented c-function erfc (complementary error function)
       
     double fun(double value)
	{
		return 0.5*erfc(-value*M_SQRT1_2);
	}
        
	  
	  in the formula to calculate put option,
	  we need to calculate value of N(-d1), then it is simply equivalent to 1-N(d1)
*/

#include<iostream>
#include<cmath>
#define e 2.7182
using namespace std;

float N(float value)
{
	return 0.5*erfc(-value*M_SQRT1_2);
}

int main()
{
	float spot_price, exercise_price;
	int ex_period;
	float rate, volatality;
	
	spot_price=165;
	exercise_price=150;
	ex_period=2;
	rate=0.06;
	volatality=0.15;
	
	/*cout<<"\nPlease enter following details";
	cout<<"\nEnter spot price : ";
	cin>>spot_price;
	cout<<"\nEnter exercise price (or strike price) : ";
	cin>>exercise_price;
	cout<<"\nEnter expiration period : ";
	cin>>ex_period;
	cout<<"\nEnter annual rate : ";
	float temp;
	cin>>temp;
	rate=temp/100;
	cout<<"\nEnter volatality (% with which spot price increase or decrease) : ";
	cin>>temp;
	volatality=temp/100;*/
	
	float call_option, put_option;
	float d1,d2;
	
	d1=(log(spot_price/exercise_price)+(rate+(volatality*volatality)/2)*ex_period)/(volatality*sqrt(ex_period));
	d2=d1-(volatality*sqrt(ex_period));

	call_option=spot_price*N(d1)-(exercise_price/pow(e,(rate*ex_period)))*N(d2);
	
	put_option = (exercise_price/pow(e,(rate*ex_period)))*(1-N(d2)) - spot_price*(1-N(d1));
	
	cout<<"\nBlack Scholes Method for Option Pricing";
	cout<<"\nSpot Price : "<<spot_price;
	cout<<"\nExercise Price : "<<exercise_price;
	cout<<"\nExpiration period : "<<ex_period;
	cout<<"\nAnnual Rate : "<<rate;
	cout<<"\nVolatality : "<<volatality;
	cout<<"\n\n---------";
	cout<<"\nValue of Call Option : "<<call_option;
	cout<<"\nValue of Pall Option : "<<put_option;
		
return 0;
}

/*
output

Black Scholes Method for Option Pricing
Spot Price : 100
Exercise Price : 120
Expiration period : 1
Annual Rate : 0.05
Volatality : 0.3

---------
Value of Call Option : 6.90395
Value of Pall Option : 21.0517

------------------------------------------------------

Black Scholes Method for Option Pricing
Spot Price : 165
Exercise Price : 150
Expiration period : 2
Annual Rate : 0.06
Volatality : 0.15

---------
Value of Call Option : 34.4971
Value of Pall Option : 2.53567
*/
