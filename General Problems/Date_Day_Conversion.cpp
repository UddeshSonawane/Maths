/*
DATE DAY CONVERSION

here we use some codes for day, month, and year

sunday    -> 1
monday    -> 2
tuesday   -> 3
wednesday -> 4
thursday  -> 5
friday    -> 6
saturday  -> 7


jan  feb  mar  apr  may  june  july  aug  sept  oct  nov  dec
 1    4    4    0    2    5     0     3    6     1    4    6
 
1500 - 1599  -> 0
1600 - 1699  -> 6
1700 - 1799  -> 4    //this pattern of (0,6,4,2) continues
1800 - 1899  -> 2
1900 - 1999  -> 0
2000 - 2199  -> 6


// to tackle we take 15 as reference with code 0
   for every year, we extract hundred and thousand place digits
   assume 'x', 
   now x-15=y
       y%4=z
       if z==0 then code=0
       if z==1 then code=6
       if z==2 then code=4
       if z==3 then code=2
   

by Uddesh

*/

#include<iostream>
using namespace std;

int main()
{
	int date, month, year, date_code, month_code, century_code;
	
	cout<<"\n**** CALENDER ****";
	
	cout<<"\nEnter Year (>1500): ";
	cin>>year;
	century_code=year;
	century_code=((century_code/100)-15)%4;
	switch(century_code)
	{
		case 0: century_code=0; break;
		case 1: century_code=6; break;
		case 2: century_code=4; break;
		case 3: century_code=2; break;
	}
	
	cout<<"\n\tJanuary : 1\n\tFebruary : 2\n\tMarch : 3\n\tApril : 4\n\tMay : 5\n\tJune : 6\n\tJuly : 7\n\tAugust : 8\n\tSeptember :9\n\tOctober : 10\n\tNovember : 11\n\tDecember : 12";
	cout<<"\nEnter Month code : ";
	cin>>month;
	month_code=month;
	switch(month_code)
	{
		case 1: 
			if(year%4==0)
				month_code=0;
			else
				month_code=1;
		break;
		case 2: 
			if(year%4==0)
				month_code=3;
			else
				month_code=4;
		break;
		case 3: month_code=4; break;
		case 4: month_code=0; break;
		case 5: month_code=2; break;
		case 6: month_code=5; break;
		case 7: month_code=0; break;
		case 8: month_code=3; break;
		case 9: month_code=6; break;
		case 10: month_code=1; break;
		case 11: month_code=4; break;
		case 12: month_code=6; break;	
	}
	
	cout<<"\nEnter date : ";
	cin>>date;
	date_code=date;
	
	int leap_year_count, yr;
	yr=year%100;                   // last two digits of year
	leap_year_count=yr/4;
	
	int temp;
	temp=(date+month_code+yr+leap_year_count+century_code)%7;
	
	string str;
	if(temp==1)
		str="Sunday";
	else if(temp==2)
		str="Monday";
	else if(temp==3)
		str="Tuesday";
	else if(temp==4)
		str="Wednesday";
	else if(temp==5)
		str="Thursday";
	else if(temp==6)
		str="Friday";
	else if(temp==0)
		str="Saturday";
		
	cout<<"\n------------------";
	cout<<"\nIt's "<<str<<" on "<<date<<"/"<<month<<"/"<<year;
	
return 0;
}

/*
output

**** CALENDER ****
Enter Year (>1500): 2020

	January : 1
	February : 2
	March : 3
	April : 4
	May : 5
	June : 6
	July : 7
	August : 8
	September :9
	October : 10
	November : 11
	December : 12
Enter Month code : 7

Enter date : 11

------------------
It's Saturday on 11/7/2020

*/
