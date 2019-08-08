#include <string>
#include <iostream>

using namespace std;

int findpos(string &str, string &sub) {
	for (unsigned int i = 0; i <= str.length(); i++)
	{
		string subcheck = str.substr(i, sub.length()); // search each position for matching string of same length
	
		if (subcheck == sub)
			{
				return i; // returns position to be passed to replace function
			}
	}
	return 0; // if not found
}


string replace(string &str, int &pos, string &sub, string &replacement) {
	{
			str.erase(pos, sub.length()); // remove old substring
			
			str.insert(pos, replacement); // insert replacement
	}
	return str;
}


int main() {
string sen, olds, news;
int position;


cout << "Enter a sentence: ";
getline(cin, sen);

cout << "Which word to replace?: ";
getline(cin, olds);

cout << "What to replace it with?: ";
getline(cin, news);


do 
{
	position = findpos(sen, olds);

 	replace(sen, position, olds, news); // pass found string to replace function
 	
} while (sen.find(olds) != string::npos); // repeat until no instances of old string are left

cout << sen << endl; 

return 0;
}

