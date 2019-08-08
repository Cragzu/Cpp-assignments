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

void negdelete(vector <int> v) {
	
	for (unsigned int x = v.size(); x > 0; x--)
	{
		if (v[x] <= 0)
		{
			v.erase(v.begin() + x);
		}
	}
	
	if (v.begin() <= 0)
	{
		v.erase(v.begin());
	}
	
	for (unsigned int y = 0; y < v.size(); y++) 
	{
		cout << v[y] << " ";
	}
	cout  << endl;	
	
}


int main() {
	srand(static_cast<unsigned>(time(0))); // randomize seed
	vector <int> vec(0); // start with empty vector of length 0
	int num;
	
	do
	{
		num = (10 - (rand()%20));
		vec.push_back(num); // push_back extends vector and inserts new item, do this 30 times
		
	}while (vec.size() < 30);
	
	cout << "The generated vector:" << endl;
	printvec(vec);
	
	cout << "Negatives removed:" << endl;
	negdelete(vec);
	
	
	return 0;
}
