#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;
int main() {
	srand(static_cast<unsigned>(time(0))); // randomize seed
	
	int d1 = 1 + (rand()%6); // random number between 1 and 6
	int d2 = 1 + (rand()%6);
	
	cout << "You rolled " << d1 << " and " << d2 << endl;
	cout << "Your score is " << (d1 + d2) << endl;
	
	return 0;
}
