#include <iostream>
#include <cmath>

using namespace std;
int main() {
	double total = 0; // total area under graph
	
	double x = 0.01; // x value
	double s = 0.01; // size of each slice
	double y = pow(x, 2); //  y = x squared
	
	for (int i = 0; i < 1000; i++) // run 1000 times
	{
		total += (s*y); // area count
		
		x += 0.01; // add to x moving along graph
		y = pow(x, 2); // y = new x squared
	}
	
	cout << "The total area is " << total << endl;

	return 0;
}

