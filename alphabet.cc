#include <iostream>
#include <vector>
#include <algorithm> // std::find

using namespace std;

int main() {
	vector <char> alpha;
	vector <char> backwards;
	
	for (int i = 65; i < (65 + 26); i++)
	{
		alpha.push_back(char(i));
	}
	
	/*for (int i = (alpha.size() - 1); i >= 0; i--)
	{
		backwards.push_back(array.at(i));
	} */
		
			
	for (unsigned int x = 0; x < alpha.size(); x++)
	{
		cout << alpha[x];
	}
	cout << endl;
	
	for (vector <char>::iterator i = alpha.begin(); i < alpha.end(); i++)
	{
		cout << *i; // dereference i
	}
	cout << endl;
	
	cout << *(alpha.begin()) << endl; // first
	cout << *(alpha.end() - 1) << endl; // last
	cout << endl;
	
	vector <char>::iterator iter;
	// find (start, end, element)
	iter = find(alpha.begin(), alpha.end(), 'C');
	if (iter == alpha.end())
	{
		cout << "Not Found" << endl;
	}
	
	else
	{
		cout << *iter << " found at location " << (iter - alpha.begin()) << endl; // index the iterator	
	}
	
	return 0;
	
}
