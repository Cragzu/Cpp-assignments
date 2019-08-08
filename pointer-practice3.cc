#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>

// create an array of 4 floats on the heap without using square brackets
// use * and ()
// pointer pointer (**) -> pointer (*) -> float
// 0.1, 1.1, 2.1, 3.1

using namespace std;

int main() {

	float** fpp; // float pointer pointer
	fpp = new float*[4]; // allocate pointers on the heap (using new)
	
	for (int i = 0; i < 4; i++)
	{
		*(fpp + i) = new float; // initialize pointers on heap
		**(fpp + i) = (i + 0.1); // assign values of the floats
		cout << **(fpp + i) << endl;  // dereference twice to get to the floats and cout them
	}
	
	for (int i = 0; i < 4; i++)
	{
		delete *(fpp + i); // delete the memory location, pointers
	}
	
	delete[] fpp; // delete the pointer pointer, use square brackets because they were used in line 16 new float
	// using the brackets deletes everything in the array, otherwise would just delete first item
	
	return 0;
	
}
	
