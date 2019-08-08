#include <iostream>

using namespace std;

struct node { // create node struct
	int i;
	node* next;
};


node* NewNode(int num){ // add a node to the list with data num
	node* np = new node;
	np->i = num;
	np->next = 0;
	return np;
}


void walk(node* nd) { // print items in the list sequentially
	
	if (nd == 0)
	{
		return;
	}
	
	cout << nd->i << " "; // print ints in list
	
	if (nd->next != 0)
	{
		walk(nd->next);
	}
	
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


// doesn't work
void shufflemerge(node* l1, node* l2, node* &merged) { // combine 2 lists into 1 in alternating order of items
	
	if (l1 == 0 && l2 == 0)
	{
		return;
	}

	if (l1 != 0)
	{
		merged = NewNode(l1->i);
		popfront(l1);
	}
	
	if (l2 != 0)
	{
		merged->next = NewNode(l2->i);
		popfront(l2);
	}

	shufflemerge(l1, l2, merged->next->next);
		
}


int main() {
	
	int array1[4] = {6, 23, 14, 200};
	node* l1 = 0;
	
	for (int x = 0; x < 4; x++)
	{
		insert(l1, array1[x]);
	}
	
	
	int array2[3] = {19, 1, 48};
	node* l2 = 0;
	
	for (int x = 0; x < 3; x++)
	{
		insert(l2, array2[x]);
	}
	
	node* merged = 0;
	
	cout << "List 1: ";
	walk(l1); // print list
	
	cout << endl << "List 2: ";
	walk(l2); // print list
	
	cout << endl << "Shuffle Merged: ";
	shufflemerge(l1, l2, merged);
	walk(merged);
	
	
return 0;
}
