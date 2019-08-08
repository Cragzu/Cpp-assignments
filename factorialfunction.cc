#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

int factorial(int &x) {
	if (x > 1)
	{
		int y = (x - 1);
		return (x * factorial(y));
	}
	else
	{
		return 1;
	}

}


int main() {
	int x;
	cout << "Enter number to find factorial: ";
	cin >> x;
	
	cout << "The factorial is " << factorial(x) << endl;
	
	return 0;
}
