#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int a = 5;
	int b = 6;
	
	// const pointer
	const int *p; // *p = 1 illegal but p = &a is legal
	// can't change value which p points to (p is a movable pointer but it's read only)
	// when const is first, value of a cannot be changed but *p can be changed to b
	
	p = &a;
	cout << *p << endl;
	p = &b;
	cout << *p << endl;
	// *p = 7; // illegal
	
	// pointer const
	int* const q(&a); // q = &b illegal but *q = 1 okay
	// must initialize q at creation. can't change location where p points to
	// when const is second, value of a can be changed but q has to always be a
	
	a = 9;
	cout << a << endl;
	*q = 8; // okay
	cout << a << " " << *q << endl;
	// q = &b; // illegal
	
	// easy way to remember if const comes first it's a movable read only pointer
	// if it comes after int* then it's a fixed arrow but read/writable
	
	// const int* const xp(&a) is possible (making both point and value fixed)
	
	
	return 0;
}
