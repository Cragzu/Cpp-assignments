#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void pickle(vector <string> s, string filename) { // filename must be in the same folder as the program for it to work
	
	bool end = false;
	string item;
	ofstream outf;
	outf.open(filename, ios::out);
	
	do // continue accepting items until user types quit
	{
		getline(cin, item);
		s.push_back(item);
		
		if (item == "quit")
		{
			end = true;
		}
	} while (!end);
		
	for (unsigned int x = 0; x < (s.size() - 1); x++)
	{
		outf << s[x] << endl; // iterate through vector and print each item to file
	}
	outf.close();
	
}


vector <string> unpickle(string filename) {
	try // catches failures
	{
		vector <string> list;
		string word;
		ifstream inf;
		inf.open(filename, ios::in);
		
		while (getline(inf, word))
		{
			list.push_back(word);
		}
		inf.close();
		
		return list;
	}
}
	

int main(int argc, char*argv[]) {
	
	cout << "Enter a grocery list, type 'quit' to finish:" << endl;
	
	vector <string> vec;
	
	pickle(vec, argv[1]);
	
	cout << endl << "Here is your grocery list:" << endl;
	
	for (unsigned int x = 0; x < (unpickle(argv[1]).size()); x++)
	{
		cout << unpickle(argv[1])[x] << endl; // iterate through vector and print each item to file
	}
	return 0;
}
