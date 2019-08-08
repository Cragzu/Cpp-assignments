#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>

// create a swap function without using &, use pointers

using namespace std;

void swap(int* x, int* y) {
	
	int* temp;
	
	temp = x;
	x = y;
	y = temp;
	
}



int main() {

	int x = 1;
	int y = 2;
	
	swap(x, y);
	
	cout << x << ", " << y;
	
	return 0;
	
}

// or this way
/*
	temp = *xp; // dereference xp (value of x)
	*xp = *yp; // swap dereferenced values
	*yp = temp;
	
}


int main() {

	int x = 1;
	int y = 2;
	
	swap(&x, &y); // pass by reference
	
	cout << x << ", " << y;
	
	return 0;
	
}
*/
