#include <iostream>

using namespace std;
int main() {
	// pre inc
	int x1 = 1;
	int y1 = ++ x1;
	cout << x1 << y1 << endl;
	
	int x2 = 1;
	int y2 = x2 ++;
	cout << x2 << y2 << endl;
	
	return 0;
	
}

/*
 * if, else, else if = same as gamemaker
 * 
 * for (int x = 0; x < 10; x++)
 * ^ same as for x in range(10)
 * 
 * while (x < 10)
 * {
 * 		(code)
 * } // typical while loop
 * 
 * do
 * {
 * 		(code)
 * } while (x < 10); // will run code at least once
 * 
 * 
