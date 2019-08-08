#include <iostream>

using namespace std;

struct node{
	string st;
	node* next;
};

// nd refers to current node being examined/modified in all these functions, equal to root

void walk(node* nd){ // print all items in list
	
	if (nd == 0)
	{
		return;
	}
	
	cout<< nd->st <<" ";
	
	if (nd->next  != 0)
	{
		walk(nd->next);
	}
}

int length(node* nd){ // find length of list and print it

	if (nd == 0)
	{
		return 0;
	}
	
	return (length(nd->next) + 1);

}

node* NewNode(string s){ // add a node to the list with data s
	node* np = new node;
	np->st = s;
	np->next = 0;
	return np;
}

//Must pass nd by ref or seg fault. We must change root node address in main.
void pushfront(node* &nd, string s){  // add item to front of list

	node* n = NewNode(s); // create a node
	
	n->next = nd; // node points to first node in the list so becomes the new first
	nd = n; // reassign nd (root)
	
}

/*void altpushfront(node* &nd, string s) {
	
	nd = new node(s, nd);
	
}*/


void popfront(node* &nd) { // remove first item in list

	if (nd != 0)
	{
		node* temp = nd->next;
		
		delete nd;
		
		nd = temp;
	}

}


/*can't pushback on root=0 since no node exists yet. So must check for it.
copy ctor called for nd pointer so root in main not changed. This is 
okay if one node already exists since we just add to the end of it.
But if no node exists yet (root=0) then we must change root addr so we
have to pass by ref also.*/

void pushback(node* &nd, string s){ // add item to end of list
	
	if (nd == 0)
	{
		nd = NewNode(s); // work is done before recursion
		return;
	}
	
	pushback(nd->next, s);

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


/* must pass nd by ref since we may need to insert at the
root node and hence change the root addr */
void insert(node* &nd, string s){ // insert a char into the correct alphabetical position in the list

	if (nd == 0) // check for empty list
	{
		nd = NewNode(s);
		return;
	}
	
	if (s < nd->st) // check if string is less than currently selected data
	{
		pushfront(nd, s); // add into the list
		return;
	}
	
	else
	{
		insert(nd->next, s);
	}

}

/* new type of recursion called tail recursion
 * have to get to the end before anything can be done */

void lfree(node* &nd){ // use delete, remove items from the stack

	if (nd == 0)
	{
		return;
	}
	
	lfree(nd->next); // move to the end and delete backwards
	
	delete nd; // work is done after recursion
	nd = 0;

}
	


int main(){
	
	const char* sarray[6] = {"b","d","a","e","f","c"};
	node* root=0;
	
	int x;
	for (x=0; x<6 ; x++)
	{
		//pushback(root, sarray[x]);
		pushfront(root, sarray[x]);
		//insert(root, sarray[x]);
		walk(root);
		cout<<endl;
	}
	for (x=0; x<3 ; x++)
	{
		cout<<"popfront"<<endl;
		popfront(root);
		walk(root);
		cout<<endl;
	}
	insert(root, "zoo");
	walk(root);
	cout<<endl;	
	/*for (x=0; x<3 ; x++)
	{
		cout<<"popback"<<endl;
		popback(root);
		walk(root);
		cout<<endl;
	}
	pushback(root, "zzz");
	walk(root);
	cout<<endl;
	
	lfree(root);*/
	return 0;
}

	
