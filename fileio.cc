#include <iostream>
#include <fstream>
using namespace std;
// dumps file to screen

int main()

{
	int x;
	string word;
	streampos e = 0;
	ifstream f; // ifstream is a datatype
	f.open("mydata.txt", ios::in);
	
	// ex #1
	while (getline(f, word) ) // line delimited
	{
		cout << word << endl;
	}
	f.clear(); // clear eof state flag from true to false
	f.seekg(0); // set seek get file pointer to beginning of file
	//f.seekg(0, ios::beg); // first arg 0 is character location
	cout << "----------------------------------------" << endl;
	
	// ex #2
	while ( f >> word ) // space delimited
	{
		cout << word << endl;
	}
	f.clear();
	f.seekg(0, ios::beg); // set seek get file pointer with offset, so 0 offset from beginning of file
	cout << "----------------------------------------" << endl;
	
	// ex #3
	while ( !f.eof() ) // eof = end of file
	{
		getline(f, word); // use with !f.eof()
		cout << word << endl;
	}
	f.close();
	return 0;
}
