#include <iostream>

using namespace std;

void swap(int &x, int &y) { // this keeps all variables separate (copy by reserve)
//void swap(int x, int y) { // this will use same x and y variables (copy by value)
	int temp;
	
	temp = x;
	x = y;
	y = temp;
}


int main() {
	int x = 1;
	int y = 2;
	
	swap(x, y);
	
	cout << x << " " << y << endl;

	return 0;
}

/*
 * functions can have the same name as long as they have different requirements
*/
