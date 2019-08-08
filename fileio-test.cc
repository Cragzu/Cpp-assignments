#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])

{
	string word;
	vector <string> vec;
	ifstream inf;
	inf.open(argv[1], ios::in);
	
	while (getline(inf, word))
	{
		vec.push_back(word);
	}
	inf.close();
	
	inf.open(argv[2], ios::in);
	
	while (getline(inf, word))
	{
		vec.push_back(word);
	}
	inf.close();

	
	string temp;
	unsigned int place = 0;
	unsigned int smallestint = 99;
	string smalleststr;
	vector <string> newvec; // new vector
		
	do
	{
		for (unsigned int i = 0; i < vec.size(); i++) // iterate through v
		{
			if (vec[i].length() <= smallestint) // check each item against smallest
			{
				if (vec[i].length() <= smallestint)
				smalleststr = vec[i]; // update smallest
				smallestint = smalleststr.length();
				place = i; // update position of smallest
			}
		}
		newvec.push_back(smalleststr); // add to new list
		vec.erase(vec.begin() + place); // remove from old list
		
		smallestint = 99; // reset smallest
		
	} while (vec.size() != 0); // repeat until no strings are left

		
	ofstream outf;
	outf.open(argv[3], ios::out);
	
	for (unsigned int x = 0; x < newvec.size(); x++) 
	{
		outf << newvec[x] << endl; // iterate through list and print each item
	}
	outf.close();
	
	return 0;
	
}
