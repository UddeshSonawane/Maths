/* MONTE CARLO SIMULATION CASINO   --- THE HOUSE ALWAYS WINS ---


*/

#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
	int dice;
	float total_fund,bet_amount;
	cout<<"\nEnter total funds available with you : ";
	cin>>total_fund;
	cout<<"\nEnter bet amount : ";
	cin>>bet_amount;
	
	/*-----------------------------------------------------------
	
	//     the following code asks user for every new turn      //
	
	float house_profit, total_play;
	char ans;
	total_play=1;
	while(1)
	{
		dice=rand()%100;
		cout<<"\nDICE : "<<dice;
		if(dice>=1 && dice<=51)
		{
			cout<<"\nHOUSE WINS";
			house_profit=house_profit+bet_amount*(2/100.0);
			total_fund=total_fund-bet_amount;
			label1:
			cout<<"\nWould you like to play more? (y/n) : ";
			cin>>ans;
			if(ans=='y' || ans=='Y')
			{
				cout<<"\nAll the best";
			}
			else if(ans=='n' || ans=='N')
			{
				cout<<"\nOkay, NP! See you again";
				break;
			}
			else
			{
				cout<<"\nPlease enter correct choice";
				goto label1;
			}
			
		}
		else
		{
			cout<<"\nPLAYER WINS";
			total_fund=total_fund+bet_amount;
			label2:
			cout<<"\nWould you like to play more? (y/n) : ";
			cin>>ans;
			if(ans=='y' || ans=='Y')
			{
				cout<<"\nAll the best";
			}
			else if(ans=='n' || ans=='N')
			{
				cout<<"\nOkay, NP! See you again";
				break;
			}
			else
			{
				cout<<"\nPlease enter correct choice";
				goto label2;
			}
		}
		total_play++;
	}
	//--------------------------------------------------------------------------
	*/
	
	int total_play;
	cout<<"\nEnter total number of plays : ";
	cin>>total_play;
	
	float house_profit;
	char ans;
	int temp, player_win_count,house_win_count;
	temp=1;
	player_win_count=0;
	house_win_count=0;
	while(temp!=total_play)
	{
		dice=rand()%100;
		if(dice>=1 && dice<=51)
		{
			house_profit=house_profit+bet_amount*(2/100.0);
			total_fund=total_fund-bet_amount;
			house_win_count++;	
		}
		else
		{
			total_fund=total_fund+bet_amount;
			player_win_count++;
		}
		temp++;
	}
	
	cout<<"\nTotal plays : "<<total_play;
	cout<<"\nPlays won by player : "<<player_win_count;
	cout<<"\nPlays won by house : "<<house_win_count;
	cout<<"\nHouse profit : "<<house_profit;
	cout<<"\nPlayer ends with "<<total_fund;
return 0;
}

/*
output

Enter total funds available with you : 10000

Enter bet amount : 100

Enter total number of plays : 20

Total plays : 20
Plays won by player : 11
Plays won by house : 8
House profit : 16
Player ends with 10300
----------------------------------------------------------

Enter total funds available with you : 10000

Enter bet amount : 100

Enter total number of plays : 80

Total plays : 80
Plays won by player : 39
Plays won by house : 40
House profit : 80
Player ends with 9900
--------------------------------------------------------------

Enter total funds available with you : 10000

Enter bet amount : 100

Enter total number of plays : 150

Total plays : 150
Plays won by player : 77
Plays won by house : 72
House profit : 144
Player ends with 10500

*/
