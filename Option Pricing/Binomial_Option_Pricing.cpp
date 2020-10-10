/*

BINOMIAL OPTION PRICING MODEL

inputs requires : spot price, exercise price(or strike price), expiration period, rate, volatality

volatalty determines the increase and decrease in spot sprice at the end of an year

ex, if volatality = 20%
    then, up price = spot price + spot price * 20%
          down price = spot price - spot price * 20%

note:  both rate and volatality will be accepted in the form of percentage
       for ex., 20%, 10%, etc
*/


#include<iostream>
using namespace std;

int main()
{
	float spot_price, exercise_price;
	int ex_period;
	float rate, volatality;
	
	spot_price=500;
	exercise_price=510;
	ex_period=3;
	rate=0.1;
	volatality=0.2;
	
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
	
	float BPT[ex_period+1][ex_period+1];  //BPT - Binomial Option Tree
	float temp1;
	BPT[0][0]=spot_price;
	for(int i=0;i<=ex_period;i++)
	{
		for(int j=i;j<=ex_period;j++)
		{
			if (j==0){/*dummy if*/}	
			else if(i==j)
			{
				BPT[i][j]=BPT[i-1][j-1]*(1-volatality);
			}
			else
			{
				BPT[i][j]=BPT[i][j-1]*(1+volatality);
			}
		}
	}
	
	/*cout<<"\nBINOMIAL OPTION TREE\n";
	for(int i=0;i<=ex_period;i++)
	{
		for(int j=i;j<=ex_period;j++)
		{
			cout<<BPT[i][j]<<"\t";
		}
		cout<<"\n";
	}*/
	
	//-------- Calculatin Risk Neutral Probability
	float p;
	p=((1+rate)-(1-volatality))/((1+volatality)-(1-volatality));

	float COP[ex_period+1][ex_period+1];  // Call Or Put   ->>> same matrix will be reused
	float cu,cd;
	cu=BPT[0][ex_period]-exercise_price;
	cd=exercise_price-BPT[ex_period][ex_period];
label_one:
	cout<<"'\nChoose the option\n1] Call Option\n2] Put Option\n\t\t -->  ";
	int choice;
	float temp2;
	cin>>choice;
	switch(choice)
	{
		case 1:
			cout<<"\nCalculation for Call Option";
			for(int i=0;i<=ex_period;i++)
			{
				temp1 = BPT[i][ex_period]-exercise_price;
				if(temp1 > 0)
					COP[i][ex_period]=temp1;
				else
					COP[i][ex_period]=0;
			}
			
			for(int j=ex_period;j>0;j--)
			{
				for(int i=0;i<ex_period;i++)
				{
					cu=COP[i][j];
					cd=COP[i+1][j];
					COP[i][j-1]=((cu*p)+(cd*(1-p)))/(1+rate);				
				}
			}
		break;
		
		case 2:
			cout<<"\nCalculation for Put Option";
			for(int i=0;i<=ex_period;i++)
			{
				temp1 = BPT[i][ex_period]-exercise_price;
				if(temp1 > 0)
					COP[i][ex_period]=0;
				else
					COP[i][ex_period]=exercise_price-BPT[i][ex_period];
			}
			
			for(int j=ex_period;j>0;j--)
			{
				for(int i=0;i<ex_period;i++)
				{
					cu=COP[i][j];
					cd=COP[i+1][j];
					COP[i][j-1]=((cu*p)+(cd*(1-p)))/(1+rate);				
				}
			}
		break;
		
		default:
			cout<<"\nPlease choose correct option";
			goto label_one;
		break;
	}
	
	cout<<"\nSpot Price : "<<spot_price;
	cout<<"\nExercise Price (Strike Price) : "<<exercise_price;
	cout<<"\nExpiration Period : "<<ex_period;
	cout<<"\nAnnual Rate : "<<rate;
	cout<<"\nVolatality : "<<volatality;
	if(choice==1)
		cout<<"\n\t\t--->> Value of Call Option : "<<COP[0][0];
	else
		cout<<"\n\t\t--->> Value of Put Option : "<<COP[0][0];
return 0;
}

/*

OUTPUT

CALL OPTION
---------------------------
Choose the option
1] Call Option
2] Put Option
		 -->  1

Calculation for Call Option
Spot Price : 500
Exercise Price (Strike Price) : 510
Expiration Period : 3
Annual Rate : 0.1
Volatality : 0.2
		--->> Value of Call Option : 133.124
		
-------------------------------------------------------------


PUT OPTION
---------------------------
Choose the option
1] Call Option
2] Put Option
		 -->  2

Calculation for Put Option
Spot Price : 500
Exercise Price (Strike Price) : 510
Expiration Period : 3
Annual Rate : 0.1
Volatality : 0.2
		--->> Value of Put Option : 16.2941
		
*/		
