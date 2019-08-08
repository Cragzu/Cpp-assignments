#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
	
	string word;
	vector <string> vec;
	ifstream inf;
	inf.open("mydata.txt", ios::in);
	
	while ( getline(inf, word) ) // line delimited
	{
		vec.push_back(word);
	}
	inf.close();
	
	sort(vec.begin(), vec.end());
	
	ofstream outf;
	outf.open("newdata.txt", ios::out);
	
	for (unsigned int x = 0; x < vec.size(); x++) 
	{
		outf << vec[x] << endl; // iterate through list and print each item
	}
	
	
	outf.close();
	
	return 0;
}

