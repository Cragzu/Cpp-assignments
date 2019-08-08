#include <vector>
#include <iostream>

using namespace std;

// create row vectors and push_back into main vector
int main() {
	
	srand(static_cast<unsigned>(time(0))); // randomize seed

	vector < vector<int> > v1; // vector that takes vectors - spacing is important to not make it a cin >>
	for (int i = 0; i < 3; i++)
	{
		vector<int> v2;
		for (int j = 0; j < 4; j++)
		{
			v2.push_back(10 + rand()%89);
		}
		v1.push_back(v2);
	}
	
	// print 2d vector
	for (unsigned i = 0; i < v1.size(); i++)
	{
		for (unsigned j = 0; j < v1[i].size(); j++)
		{
			cout << v1[i][j] << " "; // print out coordinates (row, column)
		}
		cout << endl;
	}
	
	return 0;
}

