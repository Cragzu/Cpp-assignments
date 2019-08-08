#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;
int main() {
	srand(static_cast<unsigned>(time(0))); // randomize seed
	
	int games= 0;
	
	int wins = 0;
	int losses = 0;
	
	int bet = 10;
	int hbet = 0;
	
	cout << "Let's Play Craps!" << endl;
	
	while (games < 10000) // play 10,000 games
	{
		int d1 = 1 + (rand()%6);
		int d2 = 1 + (rand()%6);
		bool end = false;
		
		if ((d1 + d2) == 2 || (d1 + d2) == 3 || (d1 + d2) == 12) // lose in first round
		{
			losses += 1;
			
			bet *= 2;
		}
		
		else if ((d1 + d2) == 7 || (d1 + d2) == 11) // win in first round
		{
			wins += 1;
			
			if (hbet < bet)
			{
				hbet = bet;
			}
			bet = 10;
		}
		
		else // move to subsequent rounds
		{
			int mark = (d1 + d2); // must match first roll
			
			while (end == false)
			{
				int nd1 = 1 + (rand()%6);
				int nd2 = 1 + (rand()%6);
				
				if ((nd1 + nd2) == mark) // win
				{
					wins += 1;
					end = true;
					
					if (hbet < bet)
					{
						hbet = bet;
					}
					bet = 10;
				}
				
				else if ((nd1 + nd2) == 7) // lose
				{
					losses += 1;
					end = true;
					
					bet *= 2;
				}
			}
		}	
		games += 1;
	}
	
	cout << "Out of 10,000 games, you won " << wins << " and lost " << losses << "." << endl;
	cout << "The highest bet was " << hbet << "." << endl;
	
	return 0;

}


/*
 * roll 2 dice
 * 
 * first roll:
 * 7 and 11 wins instantly
 * 12 3 or 2 loses instantly
 * 
 * otherwise keep rolling again until:
 * 7 - loses
 * same as first roll - wins
 * 
 * play 10,000 games
 * 
 * bet $10, double bet after every loss
 * reset bet back to $10 after every win
 * print highest bet placed in the game
 */
  
