#include <iostream> // used to import functions/libraries

using namespace std; // declaring variable type
int main() {  // main = function name, int is data type (integer)
	cout << "Hello World" << endl << "Bye" << endl; // use " for strings, endl makes a new line
	cout << 10 % -6;
	return 0; // 0 signifies successful run of program (1 is failure)
}

/*
 * line to compile: g++ -c helloworld.cc
 * line to link: g++ helloworld.o helloworld
 * shortcut to do both: g++ helloworld.cc -o helloworld
 * run program with ./helloworld
 * or use f9 f5 to compile and run

 * { } signify the inside of functions, c++ doesn't recognize indentation but do it anyway
 * { = open scope, } = scope resolution operator

 * the ; signifies end of a line/statement like gamemaker
*/
