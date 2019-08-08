#include <iostream>

using namespace std;
int main() {
	int change;
	cout << "Enter the amount of change : ";
	cin >> change;
	cout << endl;
	
	int quarters(change / 25);
	change -= (quarters * 25);
	
	int dimes(change / 10);
	change -= (dimes * 10);
	
	int nickels(change / 5);
	change -= (nickels * 5);
	
	cout << "Quarters: " << quarters << endl;
	cout << "Dimes: " << dimes << endl;
	cout << "Nickels: " << nickels << endl;
	cout << "Pennies: " << change << endl;

	return 0;
	
}


