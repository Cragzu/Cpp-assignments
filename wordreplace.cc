#include <string>
#include <iostream>

using namespace std;

int main() {
string sen, olds, news;

cout << "Enter a sentence: ";
getline(cin, sen);

cout << "Which word to replace?: ";
getline(cin, olds);

cout << "What to replace it with?: ";
getline(cin, news);

do 
{
 	sen.replace(sen.find(olds), olds.length(), news); // replace takes position and length of substring, and new one
 	
} while (sen.find(olds) != string::npos); // repeat until no instances of old string are left

cout << sen << endl; 

return 0;
}
