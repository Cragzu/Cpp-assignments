#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>

// create an array of 4 floats on the heap - use pointers
// 0.1, 1.1, 2.1, 3.1

using namespace std;

int main() {

	float* A[4]; // initialize array of 4 float pointers
	
	for (int i = 0; i < 4; i++)
	{		
		A[i] = new float; // new puts it on the heap instead of stack
		*A[i] = (i + 0.1);
		cout << *A[i] << endl;
	}
	
	for (int i = 0; i < 4; i++)
	{
		delete A[i]; // no brackets after delete because new float had no brackets
	}
	
	return 0;
	
}
