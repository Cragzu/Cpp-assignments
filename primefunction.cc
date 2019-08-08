#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

bool IsPrime(long x) {
	
	for (long i = (x - 1); i > 1; i--)
	{
		if (x % i == 0) // if x has other factors
		{
			return false;
		}
	}
	return true;
}


int main() {
	long x;
	cout << "Enter number: ";
	cin >> x;
	
	if (IsPrime(x) == 0)
	{
		cout << "It is not prime." << endl;
	}
	
	else if (IsPrime(x) == 1)
	{
		cout << "It is prime." << endl;
	}
	
	cout << "All primes between 2 and 100:" << endl;
	
	for (long z = 2; z <= 100; z++)
	{
		if (IsPrime(z) == 1)
		{
			cout << z << " ";
		}
	}
	
	return 0;
}
