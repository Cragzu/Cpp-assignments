#include <stdio.h>
#include <fstream> // ofstream ifstream
#include <iostream>

using namespace std;

int main() {
	
	char ** v; // v is a pointer to a char pointer
	v = new char* [64]; // hope there are less than 64 words in file
	ifstream inf;
	inf.open("fruit.txt", ios::in); // reading
	unsigned int c = 0; 
	while ( !inf.eof() ) // last iteration will be eof char
	{
		v[c] = new char [32]; // hope no words over 32 letters
		inf >> v[c]; // no bounds checking for stream insertion
		
	
	
	
	
	
	
	
	
	
	
	
	
return 0;	
	
}
