#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

int GCF(int &n1, int &n2) {
	int greatest = 1;
	
	for (int i = 1; i <= n1; i++) // check all numbers between n1 and 1
	{
		if (n1 % i == 0 && n2 % i == 0) // check if it is a factor of both
		{
			greatest = i; // will always be larger than previous b/c of adding
		}
	}
	return greatest;
}


int main() {
	int n1, n2;
	cout << "Enter first number: ";
	cin >> n1;
	cout << "Enter second number: ";
	cin >> n2;
	
	cout << "The GCF is " << GCF(n1, n2) << endl;
	
	return 0;
}

