#include <iostream>

using namespace std;

struct node { // create node struct
	int i;
	node* next;
};


void walk(node* nd) { // print items in the list sequentially
	
	if (nd == 0)
	{
		return;
	}
	
	cout << nd->i << " "; // print ints in list
	
	if (nd->next != 0)
	{
		walk(nd-> next);
	}
	
}


node* NewNode(int num){ // add a node to the list with data num
	node* np = new node;
	np->i = num;
	np->next = 0;
	return np;
}


void pushfront(node* &nd, int num){  // add item to front of list

	node* n = NewNode(num); // create a node
	
	n->next = nd; // node points to first node in the list so becomes the new first
	nd = n; // reassign nd (root)
	
}


void insert(node* &nd, int num){ // insert an int into the correct position in the list
	
	if (nd == 0) // check for empty list
	{
		nd = NewNode(num);
		return;
	}
	
	if (num < nd->i) // check if string is less than currently selected data
	{
		pushfront(nd, num); // add into the list
		return;
	}
	
	else
	{
		insert(nd->next, num);
	}

}


void removedups(node* root) {
	
	if (root == 0)
	{
		return;
	}
	
	if (root->i == root->next->i) // if selected int and next int are equal
	{
		node* temp = root->next->next; // save third int
		
		delete root->next; // remove next int
		
		root->next = temp; // third int becomes next int
	}
	
	removedups(root->next); // recursion
	
}


int main() {
	
	int iarray[6] = {1, 2, 1, 3, 2, 3};
	node* root = 0;
	
	for (int x = 0; x < 6; x++)
	{
		insert(root, iarray[x]);
	}
	
	cout << "Sorted: ";
	walk(root); // print list
	
	cout << endl << "Duplicates Removed: ";
	removedups(root);
	walk(root); // print again
	
	
return 0;
}
