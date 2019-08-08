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


void pushback(node* &nd, int num){ // add item to end of list
	
	if (nd == 0)
	{
		nd = NewNode(num); // work is done before recursion
		return;
	}
	
	pushback(nd->next, num);

}


void pushfront(node* &nd, int num){  // add item to front of list

	node* n = NewNode(num); // create a node
	
	n->next = nd; // node points to first node in the list so becomes the new first
	nd = n; // reassign nd (root)
	
}


void popfront(node* &nd) { // remove first item in list

	if (nd != 0)
	{
		node* temp = nd->next;
		
		delete nd;
		
		nd = temp;
	}

}


void popback(node* &nd){ // remove last item from list

	if (nd == 0)
	{
		return;
	}

	if (nd->next == 0) // standard recursion, work is performed before recursive loop
	{
		delete nd;
		nd = 0;
		return;
	}
	
	popback(nd->next);

}


int length(node* nd){ // find length of list and print it

	if (nd == 0)
	{
		return 0;
	}
	
	return (length(nd->next) + 1);

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


void reverse(node* &root) { // make the list backwards 
	
	node* nd = 0; // new node for new link list
	
	while (root != 0) // repeat until everything removed from old list
	{
		pushfront(nd, root->i); // add first item from old to front of new, reversing order
		popfront(root); // remove first item in old
	}
	
	root = nd; // assign variable to make original = new list
	
	
	//Alternative Method
	/*if (root == 0)
	{
		return;
	}
	
	node* first == root;
	node* rest == first->next;
	
	if (rest == 0)
	{
		return;
	}
	
	reverse(rest);
	
	first->next->next = first;
	first->next = 0;
	root = rest; */
	
}


int main() {
	
	node* root = 0;
	
	int iarray[6] = {1, 7, 9, 2, 5, 6};
	
	for (int x = 0; x < 6; x++)
	{
		insert(root, iarray[x]);
	}
	
	cout << "Sorted: ";
	walk(root); // print list
	
	cout << endl << "Reversed: ";
	reverse(root);
	walk(root);
	
	return 0;
	
}
	
