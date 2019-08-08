#include <string>
#include <iostream>

/* 11:00 - 11:22 (22 min)
 * 
 * How many of the parking spaces were occupied both yesterday and today?
 * 
 * first line is int N for number of spaces
 * next 2 lines are strings of N length with C for occupied and . for empty
 * 
 * output number of spaces occupied on both days
 * 
*/

using namespace std;

int main() {
	
	int count = 0;
	
	int N;
	string d1, d2;
	
	cin >> N;
	cin >> d1;
	cin >> d2;
	
	
	
	for (int i = 0; i < N; i++)
	{
		if (d1[i] == 'C')
		{
			if (d2[i] == 'C')
			{
				count += 1;
			}
		}
	}
	
	cout << count;


	return 0;

}
