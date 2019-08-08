#include <string>
#include <iostream>

/* 11:15 - 11:21 (6 min)
 * 
 * players in a tournament play 6 games, no ties
 * 
 * 5 or 6 wins = group 1
 * 3 or 4 games = group 2
 * 1 or 2 games = group 3
 * 0 games = disqualified (-1)
 * 
 * accept 6 lines of input with W or L
 * place person in appropriate group
 * 
*/

using namespace std;

int main() {
	
	int wins = 0;
	int losses = 0;
	string letter;
	
	for (int i = 0; i < 6; i++)
	{
		cin >> letter;
		if (letter == "W")
		{
			wins++;
		}
		else
		{
			losses++;
		}
	}
	
	if (wins == 5 || wins == 6)
	{
		cout << "1";
	}
	
	if (wins == 3 || wins == 4)
	{
		cout << "2";
	}
	
	if (wins == 1 || wins == 2)
	{
		cout << "3";
	}
	
	if (wins == 0)
	{
		cout << "-1";
	}
	
	
	return 0;
	
}
