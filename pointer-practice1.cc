#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>

// create an array of 4 floats on the stack
// 0.1, 1.1, 2.1, 3.1

using namespace std;

int main() {

	float A[4]; // initialize array of 4 floats
	
	for (int i = 0; i < 4; i++)
	{
	A[i] = (i + 0.1);
	}
	
	for (unsigned int i = 0; i < 4; i++)
	{
		cout << A[i] << endl;
	}
	
	return 0;
	
}
	
