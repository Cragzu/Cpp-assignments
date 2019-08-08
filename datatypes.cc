#include <iostream>

using namespace std;
int main() {
	cout << "hello" << endl;
	
	int i(-1);
	i = 2147483647; // biggest int
	i = -2147483648; // smallest int
	cout << i << endl;
	
	unsigned int ui(1);
	ui = 4294967295; // biggest unsigned int
	ui = 0; // smallest unsigned int
	cout << ui << endl;
	
	long int l(999999999);
	short s(9);
	float f(-15.5);
	double d(9.11e-33);
	char c('A');
	char c2(66);
	bool b(false); // 0
	bool b2(true); // 1 or anything else
	bool b3(88); // anything other than 0 is true
	
	//int* p = 0;
	//cout << *p;
	
	cout << "int " << sizeof(i) << endl;
	cout << "long " << sizeof(l) << endl;
	cout << "unsigned int " << sizeof(ui) << endl;
	cout << "short " << sizeof(s) << endl;
	cout << "float " << sizeof(f) << endl;
	cout << "double " << sizeof(d) << endl;
	cout << "char " << sizeof(c) << endl;
	cout << "char c2 = " << short(c2) << " with a size of " << sizeof(c2) << endl;
	cout << char(67) << endl;
	cout << "bool size " << sizeof(b) << endl;
	cout << "bool b2 " << b2 <<"    b " << b << endl;
	
	int x = 10;
	int y = 3;
	cout << float(x)/y << endl; //changing data type on the fly, called casting. usually not recommended
	
	return 0;
}

	
	
