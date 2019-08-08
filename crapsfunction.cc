#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

int rolldice() {
	return 1 + (rand()%6);
}


bool playgame(int &d1, int &d2) {
	if ((d1 + d2) == 2 || (d1 + d2) == 3 || (d1 + d2) == 12) // lose in first round
		{
		return false;
		}
		
		else if ((d1 + d2) == 7 || (d1 + d2) == 11) // win in first round
		{
			return true;
		}
		
		else // move to subsequent rounds
		{
			int mark = (d1 + d2); // must match first roll
			
			while (true)
			{
				int nd1 = rolldice();
				int nd2 = rolldice();
				
				if ((nd1 + nd2) == mark) // win
				{
					return true;
				}
				
				else if ((nd1 + nd2) == 7) // lose
				{
					return false;
				}
			}
		}	
	}


int main() {
	srand(static_cast<unsigned>(time(0))); // randomize seed
	
	int games= 0;
	
	int wins = 0;
	int losses = 0;
	
	cout << "Let's Play Craps!" << endl;
	
	while (games < 10000) // play 10,000 games
	{
		int d1 = rolldice();
		int d2 = rolldice();

		bool result = playgame(d1, d2);
		
		if (result == true)
		{
			wins += 1;
		}
		else
		{
			losses += 1;
		}
		
		games += 1;
	}
	
	cout << "Out of 10,000 games, you won " << wins << " and lost " << losses << "." << endl;
	
	return 0;

}
