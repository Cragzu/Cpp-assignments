#include <vector>
#include <iostream>
#include <map>

using namespace std;

int main() {
	
	map < string, int > nameage; // declare the map with string and int pairs
	
	nameage["bob"] = 23;
	nameage["sarah"] = 21;
	nameage["bob"] = 5;
	//nameage.erase("sarah"); // removes sarah from map
	
	map < string, int >::iterator i;
	
	for (i = nameage.begin(); i != nameage.end(); i++)
	{
		cout << i->first << ": " << i->second << endl;
	}
	
	if (nameage.find("bob") != nameage.end())
	{
		cout << nameage["bob"] << endl;
	}
	
	
return 0;	
	
}
