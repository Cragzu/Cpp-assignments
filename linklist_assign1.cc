#include <string>
#include <iostream>

using namespace std;

struct node { // nodes are containers in linked lists holding values
	
	string data;
	node* next; // node pointer meaning next item in the list
	
};

// "(*nd).next" and "nd->next" are equivalent, but latter is accepted practice

void printlist(node* current) { // recursive print list
	
	cout << current->data << endl; // print current data
	
	if (current->next != 0) // continue until end is reached
	{
		printlist(current->next); // call function again if pointer is not 0
	} 
	
	// alternatively, check: if (current == 0), return and cout otherwise
	// does the same thing with one more recursion loop, but it will work if there is only one item in the list unlike mine
	
}


int main() {
	
	node* root; // node pointer
	root = new node; // create first container
	root->data = "one"; // same as (*root).data = "one", points to next item in the list

	root->next = new node; // create next node, second container
	(root->next)->data = "two"; // assign data
	
	(root->next)->next = new node; // third container
	((root->next)->next)->data = "three"; // assign data
	
	((root->next)->next)->next = 0; // create null pointer to signify end of list
	
	
	printlist(root); // print all data
	
	
	/*
	// how to print all data manually
	cout << root->data << endl;
	cout << (root->next)->data << endl;
	cout << ((root->next)->next)->data << endl;
	*/
	
	// delete all nodes backwards, to be able to still access everything
	// deleting root first would lose acess to all the others
	delete (root->next)->next;
	delete root->next;
	delete root;
	
	
	
	return 0;
	
}
