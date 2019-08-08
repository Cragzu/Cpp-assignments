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


void popfront(node* &nd) { // remove first item in list

	if (nd != 0)
	{
		node* temp = nd->next;
		
		delete nd;
		
		nd = temp;
	}

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


void split(node* root, node* &front, node* &back) {
	
	int len = length(root);
	len /= 2; // divide len by 2
	
	int count = 0;
	
	while (count < len)
	{
		insert(front, root->i);
		count += 1;
		popfront(root);
	}
	
	while (count < (len*2))
	{
		insert(back, root->i);
		count += 1;
		popfront(root);
	}
	
}


int main() {
	
	node* root = 0;
	node* front = 0;
	node* back = 0;
	
	int iarray[6] = {1, 7, 9, 2, 5, 6};
	
	for (int x = 0; x < 6; x++)
	{
		insert(root, iarray[x]);
	}
	
	cout << "Sorted: ";
	walk(root); // print list
	
	split(root, front, back);
	
	cout << endl << "Front: ";
	walk(front);
	cout << endl << "Back: ";
	walk(back);
	
	
return 0;
}

