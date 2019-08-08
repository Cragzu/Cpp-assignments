#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

void printvec(vector <int> v) {
	
	for (unsigned int x = 0; x < v.size(); x++) 
	{
		cout << v[x] << " "; // iterate through list and print each item
	}
	cout  << endl;	
}


void sortvec(vector <int> v) { // insertion sort - not in place (making two separate vectors)
	int current;
	vector <int> newvec; // new vector
	
	while (!v.empty())
	{
		current = v.back(); // last item in vector
		v.pop_back(); // remove last
		
		if (newvec.empty())
		{
			newvec.push_back(current); // add first item to new
		}
		
		else
		{
			for (unsigned int i = 0; i < newvec.size(); i++) // iterate through new
			{
				if (current < newvec[i]) // check current against each item
				{
					newvec.insert((newvec.begin() + i), current); // insert item in its place
					break;
				}
				
				else if  (i == (newvec.size() - 1)) // if we reach the end of the list
				{
					newvec.push_back(current); // insert at the end
					break;
				}
			}
		}
	}
		
	for (unsigned int x = 0; x < newvec.size(); x++) 
	{
		cout << newvec[x] << " "; // print new list
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
