#include <iostream>
#include <stdio.h>
#include <ctime>
#include <string.h> // strncpy
using namespace std;

int main() {
	
	srand(static_cast<unsigned>(time(0))); // randomize seed
	
	int* p[50]; // initialize array of 50 int pointers
	
	for (int i = 0; i < 50; i++)
	{
		// new = able to be deleted
		p[i] = new int; // allocate memory location in each position in the array
		int num = 100 + rand()%899; // create random numbers from 100 to 999 (use 899 as it is 100 less than 999)
		*p[i] = num; // put the numbers in the array
		
	}
	
	
	// bubble sort
	bool sorted;
	int t;
	
	do
	{
		sorted = true;
		
		for (unsigned int x = 0; x < 49; x++) {
			if (*p[x] > *p[x+1]) // check values of ints in the array
			{
				t = *p[x]; // set temp value
				*p[x] = *p[x+1]; // swap the two ints
				*p[x+1] = t;
				
				sorted = false;
			}
		}
	} while (!sorted);
	
	
	
	for (int i = 0; i < 50; i++) // print sorted vector
	{
		cout << *p[i] << " ";
	}
	
	
	cout << endl << "p: " << p << endl; // these will both be pointers
	cout << "*p: " << *p << endl;
	
	
	for (int i = 0; i < 50; i++) // clean up after myself
	{
		delete p[i]; // free up memory and relinquish ownership of it
			// delete[] p[i]; 
			// the [] brackets on delete would be if there were brackets on assignment, (eg new int[256])
			// used to delete everything in the array
	}
	
	return 0;
	
}
