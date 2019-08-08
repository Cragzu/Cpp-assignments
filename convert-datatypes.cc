#include <cstdio> // for printf
#include <cstring> // for string methods
#include <iostream> // for cout and cin
#include <cstdlib> // for atoi
#include <sstream> // for stringstream

using namespace std;
int main() {
	int x; // declaration
	x = 1; // assignment
	// int y = 1; // both of above
	// int z(1); // same as above
	
	string name; // new C++ string type
	name = "bob";
	cout << name << endl;
	
	char cname[256]; // old style c string which is a char array
	strncpy(cname, "bobby", 256);
	printf("my name is %s \n", cname);
	
	cout << "Hello World!\n";
	cout << "Hello World!" << endl; // endl flushes the output buffer
	
	/*
	 * cin >> name; // rob ark (only rob was extracted from input stream since cin uses spaces as separators)
	 * cout << name << endl; // rob
	 * cin >> name; // won't ask for input since 'ark' is still waiting to be read
	 * cout << "this string was still in the input stream: " << name; //ark
	 */
	 
	 getline(cin, name); // can input strings with spaces
	 cout << name << endl;
	 
	 cin.getline(cname, 256); // this uses old style char arrays
	 printf("%s", cname);
	 
	 // example convert string -> int
	 string age("14"); // or string age = "14"
	 cout << atoi(age.c_str()) +1 << endl;
	 //age.c_str() convert c++ to c string
	 
	 // example convert int -> string
	 int num(14);
	 stringstream ss;
	 ss << num;
	 cout << ss.str() << endl;
	 
	 // example of c-string -> double
	 char n[32];
	 strncpy(n, "12", 32);
	 cout << strtod(n, NULL) + 1;
	 
	 // example of c++ string -> double
	 string nn("12.03");
	 cout << endl << strtod(nn.c_str(), NULL) + 1;
	 
	 return 0;
	 
}
	
	
	
	
	
	
	
	
