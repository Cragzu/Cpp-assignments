#include <iostream>

using namespace std;
int main() {
	
	int n1 = 0; // first number
	int n2 = 1; // second number
	
	int sum = 0; // placeholder spot
	
	cout << n1 << endl;
	
	for (int i = 0; i < 20; i++) // run 20 times
	{
		cout << n2 << endl;
		
		sum = n1 + n2; // the sum
		n1 = n2; // first becomes second
		n2 = sum; // second becomes sum
	}

	return 0;
}

