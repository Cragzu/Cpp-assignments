#include <string>
#include <iostream>

/* 11:28 - new class (45 min?)
 * 
 * take inputs to print out a custom trident made of *
 * 
 * accept 3 ints, each between 0 and 10:
 * t = height of tines
 * s = spacing between tines
 * h = length of the handle
 * 
 * length of base = t + (2s)
 * 
 * handle pos =  2 + s
 * 
*/

using namespace std;

int main() {
	
	int t, s, h;
	
	cin >> t;
	cin >> s;
	cin >> h;
	
	int base = (t + (s*2));
	int handle = (s + 1);
	
	string spaces;
	string tinerow;
	
	for (int j = 0; j < s; j++) // print number of spaces
	{
		spaces += " ";
	}
	
	tinerow = "*" + spaces + "*" + spaces + "*";


	for (int q = 0; q < t; q++) // tine length
	{
		cout << tinerow;
		if (q!= t)
		{
			cout << endl;
		}
	}	
	
	for (int i = 0; i < base; i++) // print base
	{
		cout << "*";
	}
	cout << endl;
	
	for (int i = 0; i < h; i++) // h times
	{
		for (int j = 0; j < base; j++) // print handle
		{
			if (j == handle)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}	
		}
	cout << endl;	
	}	
			
	
	
	return 0;
	
}
