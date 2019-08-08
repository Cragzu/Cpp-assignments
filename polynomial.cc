#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

void quadratic(double a, double b, double c, double &x1, double &x2) {
	
	x1 = ((-b + pow(((pow(b, 2)) - 4*a*c), 0.5)) / (2*a)); // quadratic formula
	x2 = ((-b - pow(((pow(b, 2)) - 4*a*c), 0.5)) / (2*a));
	
	cout << "x = " << x1 << endl;
	cout << "x = " << x2 << endl;
}


int main() {
	
	double a, b, c, x1, x2;
	
	cout << "A: ";
	cin >> a;
	
	cout << "B: ";
	cin >> b;
	
	cout << "C: ";
	cin >> c;
	
	quadratic(a, b, c, x1, x2);
	
return 0;
}
