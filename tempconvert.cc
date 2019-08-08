#include <iostream>

using namespace std;
int main() {
	double temp;
	cout << "Enter temperature in Celsius: " ;
	cin >> temp;
	cout << endl;
	
	cout << "Temperature in Fahrenheit: " << (temp*1.8 + 32) << endl;
	return 0;
}
