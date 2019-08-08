#include <vector>
#include <iostream>

using namespace std;

int getsum(vector <int> v) { // returns the sum of all ints in a vector
	
	int sum = 0;
	
	for (unsigned int x = 0; x < v.size(); x++) // iterate through v
	{
		sum += v[x]; // add each value to total
	}
	
	return sum;
	
}


void sortvec(vector < vector<int> > &v) { // use bubble sort
	// if last int in each mini vector is bigger then swap the whole vectors
	bool sorted;
	vector <int> t;
	
	do
	{
		sorted = true;
		
		for (unsigned int x = 0; x < (v.size() - 1); x++) {
			if (v[x].back() > v[x+1].back()) // check last number in each vector against the next
			{
				t = v[x]; // set temp value
				v[x] = v[x+1]; // swap the two vectors
				v[x+1] = t;
				
				sorted = false;
			}
		}
	} while (!sorted);
		
	cout << "Sorted Vector" << endl; // print generated vector
	for (unsigned i = 0; i < v.size(); i++)
	{
		for (unsigned j = 0; j < (v[i].size() - 1); j++)
		{
			cout << v[i][j] << " "; // print out coordinates (row, column)
		}
		cout << "	sum: " << v[i].back(); // print sum of vector
		cout << endl;
	}
		
}


int main() { // create row vectors and push_back into main vector
	
	srand(static_cast<unsigned>(time(0))); // randomize seed

	vector < vector<int> > v1; // vector that takes vectors - spacing is important to not make it a cin >>
	for (int i = 0; i < 6; i++)
	{
		vector<int> v2;
		for (int j = 0; j < 6; j++)
		{
			v2.push_back(10 + rand()%89); // add 6 vectors of 6 random numbers each
		}
		v2.push_back(getsum(v2));
		v1.push_back(v2);
	}
	
	cout << "Original Vector" << endl; // print generated vector
	for (unsigned i = 0; i < v1.size(); i++)
	{
		for (unsigned j = 0; j < (v1[i].size() - 1); j++)
		{
			cout << v1[i][j] << " "; // print out coordinates (row, column)
		}
		cout << "	sum: " << v1[i].back(); // print sum of vector
		cout << endl;
	}
	
	cout << endl;
	sortvec(v1); // print sorted version
	
	return 0;
}
