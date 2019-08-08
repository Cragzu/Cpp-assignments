#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main() {
	 
	vector <string> v(64,"Hello");
	for (unsigned int x=0; x < v.size(); x++)
	{
			cout << v[x] <<endl;
	}
	
	char* array[64];
	int x;
	for (x = 0; x < 64; x++)
	{
		array[x] = new char[256];
		strncpy(array[x], "Hello", 255);
		printf("%d: %s\n", x, array[x]);
	}
	
	cout << "array = " << array << endl;
	cout << "array[0] = " << array[0] << endl; // Hello
	cout << "array[0][0] = " << array[0][0] << endl;
	
	for (int x = 0; x < 64; x++)
	{
		delete[] array[x];
	}
	
	return 0;
	
}
 
