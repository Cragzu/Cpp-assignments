#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

void fib(int &steps, int &n1, int &n2, int &sum, int &count) {
	count += 1;
	
	cout << n2 << endl;
	
	sum = n1 + n2; // the sum
	n1 = n2; // first becomes second
	n2 = sum; // second becomes sum
	
	if (count < steps)
	{
		fib(steps, n1, n2, sum, count);
	}
	
	else
	{
		return;
	}
}


int main() {
	
	int n1 = 0; // first number
	int n2 = 1; // second number
	
	int sum = 0; // placeholder spot
	
	int count = 1;
	
	int steps;
	cout << "Enter number of steps in the sequence: ";
	cin >> steps;
	
	cout << n1 << endl;
	fib(steps, n1, n2, sum, count);
	
	return 0;
}
