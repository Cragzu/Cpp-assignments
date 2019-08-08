#include <iostream>

using namespace std;
int main() {
	int count = 0;
	
	int orig1;
	cout << "First Number: ";
	cin >> orig1; // first original
	
	int orig2;
	cout << "Second Number: ";
	cin >> orig2; // second original
	
	int n1 = orig1; // new numbers
	int n2 = orig2;
	int sum = 0; // placeholder
	
	cout << n1 << " ";
	
	do
	{
		cout << n2 << " ";
		
		sum = ((n1 + n2) % 10); // sum of digits, only keeping the ones
		n1 = n2; // first becomes second
		n2 = sum; // second becomes sum
		
		count += 1; // keep track of steps
	
	} while (n1 != orig1 || n2 != orig2); // run until both numbers equal original numbers
	
	cout << n2 << endl;
	cout << "Your numbers required " << count << " steps." << endl;
	
	return 0;
}

/*
 * Necklace Problem
 * input 2 numbers
 * add them together, only keeping the ones digit
 * continue adding in sequence until the last 2 are the same as the first 2
 */
