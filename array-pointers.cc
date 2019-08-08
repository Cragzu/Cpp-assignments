#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int numbers[5]; // an array in C is a pointer. similar to a vector but cannot be manipulated, this one has 5 slots
	*numbers = 10; // it points to the first element of the array
	cout << numbers[0] << endl; // output is 10
	numbers[1] = 99; // second element
	cout << *(numbers + 1) << endl; // output is 99, pointer arithmetic (really adding numbers + 1(4))
	cout << &numbers[0] << " " << &numbers[1] << endl;
	
	
	int * p;
	p = numbers;
	*p = 10;
	
	p++;
	*p = 20;
	p = &numbers[2];
	*p = 30;
	p = numbers + 3;
	*p = 40;
	p = numbers;
	*(p+4) = 50;
	
	for (int n = 0; n < 5; n++)
	{
		cout << numbers[n] << ", ";
	}
	
	cout << endl;
	
	for (int n = 0; n < 5; n++)
	{
		cout << *(p + n) << ", "; // same as above
	}
	
		
	
	return 0;
	
}
