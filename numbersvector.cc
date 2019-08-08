#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

void printvec(vector <int> &v) {
	
	for (unsigned int x = 0; x < v.size(); x++) {
		cout << v[x] << " ";
	}
	cout << endl;	
}

void sortvec(vector <int> &v) { // bubble sort
		bool sorted;
		int t;
		
		do
		{
			sorted = true;
			
			for (unsigned int x = 0; x < v.size()-1; x++) {
				if (v[x] > v[x+1])
				{
					t = v[x]; // set temp value
					v[x] = v[x+1]; // swap the two numbers
					v[x+1] = t;
					
					sorted = false;
				}
			}
		} while (!sorted);
		
	for (unsigned int y = 0; y < v.size(); y++) {
		cout << v[y] << " ";
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
