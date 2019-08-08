#include <iostream>

using namespace std;
int main() {
	string name;
	cout << "Please enter your name: ";
	getline(cin, name);
	cout << endl;
	
	int age;
	cout << "Now enter your age: ";
	cin >> age;
	cout << endl;

	cout << "Hello, " << name << ". You are " << age << " years old." << endl;
	cout << "You literally just told me that but I'll repeat it in case you're a goldfish. :)" << endl;
	
	return 0;
}
