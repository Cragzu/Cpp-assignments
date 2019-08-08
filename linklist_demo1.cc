#include <string>
#include <iostream>

using namespace std;

struct node {
	
	string data;
	node* np;
	
};


int main() {
	
	node a, b;
	node* root = &a; // root points to a
	
	a.data = "hello";
	a.np = &b; // a points to b
	
	b.data = "goodbye";
	b.np = 0;
	
	return 0;
	
}
