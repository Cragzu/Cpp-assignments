#include <iostream>
#include <cmath>

using namespace std;

int main() {
	try
	{
		int* x = 0;
		cout << *x;
	}
	catch (int e) // e = error code
	{
		cout << e << endl;
	}
	
	return 0;
}
		
