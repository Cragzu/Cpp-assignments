#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

void printvec(vector <int> &v) {
	
	for (unsigned int x = 0; x < v.size(); x++) 
	{
		cout << v[x] << " "; // iterate through list and print each item
	}
	cout << endl;	
}


/*void sortvec(vector <int> &v) { // selection sort - not in place (making two separate vectors)
		int smallest = 99;
		unsigned int place;
		vector <int> newvec(0); // new vector
		
		do
		{
			for (unsigned int i = 0; i < v.size(); i++) // iterate through v
			{
				if (v[i] < smallest) // check each item against smallest
				{
					smallest = v[i]; // update smallest
					place = i; // update position of smallest
				}
			}
			v.erase(v.begin() + place); // remove from old list
			newvec.push_back(smallest); // add to new list
			
			smallest = 99; // reset smallest
			
		} while (v.size() != 0); // repeat until no numbers are left
		
		
		
	for (unsigned int y = 0; y < newvec.size(); y++) 
	{
		cout << newvec[y] << " "; // print new list
	}
	cout << endl;	
		
}
*/


void sortvec(vector <int> &v) { // selection sort - in place (using the same vector - memory saving)
	int smallest = 100;
	unsigned int place = 0;
	
	for (unsigned int count = 0; count < v.size(); count++) // do this for as many times as vector length
	{
		for (unsigned int i = count; i < v.size(); i++) // iterate through v at each position
		{
			if (v[i] < smallest) // check each item against smallest
			{
				smallest = v[i]; // update smallest
				place = i; // update position of smallest
			}
		}
		v.erase(v.begin() + place); // remove from old list
		v.insert((v.begin() + count), smallest); // add to new list
		
		smallest = 100; // reset smallest
	}
	
		
	for (unsigned int y = 0; y < v.size(); y++) 
	{
		cout << v[y] << " "; // print new list
	}
	cout << endl;	
		
}

int main() {
	srand(static_cast<unsigned>(time(0))); // randomize seed
	vector <int> vec(0); // start with empty vector of length 0
	bool dup;
	int num;
	
	do
	{
		do
		{
			dup = true;
			num = rand()%99;
			for (unsigned int x = 0; x < vec.size(); x++) // iterate through vector checking for duplicates
			{
				if (vec[x] == num)
				{
					dup = false;
				}
			}
		} while (!dup);
			vec.push_back(num); // push_back extends vector and inserts new item, do this 30 times
	} while (vec.size() < 30);
	
	cout << "The generated vector:" << endl;
	printvec(vec);
	
	
	cout << "The sorted vector:" << endl;
	sortvec(vec);
	
	return 0;
}
