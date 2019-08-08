#include <iostream>
#include <queue>
#include <algorithm>
#include <map>

/* 
 * take a string of characters
 * split the string up, find the number of occurrences of each character
 * put each into a node and make a linked list, greatest to least number and alphabetical within the same number
 * 
 * combine the last two nodes in the linked list to make a root node with the two nodes being its children, insert
 * back into the linked list. do this repeatedly until left with only one parent node.
 * 
 * traverse through the tree and create a hash table of the binary codes for each letter
 */

using namespace std;

struct node {
	int i;
	string s;
	node* next;
	node* left;
	node* right;

};


node* NewNode(string str, int num) { // add a node to the list with data s
	node* np = new node;
	np->s = str;
	np->i = num;
	
	np->next = 0;
	np->left = 0;
	np->right = 0;
	return np;
}


void walk(node* nd){ // print all items in list
	
	if (nd == 0)
	{
		return;
	}
	
	cout << nd->s << ": " << nd->i << endl;
	
	if (nd->next  != 0)
	{
		walk(nd->next);
	}
}


void pushfront(node* &nd, string str, int num){  // add item to front of list

	node* n = NewNode(str, num); // create a node
	
	n->next = nd; // node points to first node in the list so becomes the new first
	nd = n; // reassign nd (root)
	
}


void insert(node* &nd, string str, int num){ // insert a node in the list, number priority then letter

	if (nd == 0) // check for empty list
	{
		nd = NewNode(str, num);
		return;
	}
	
	if (num > nd->i) // check if number is greater than currently selected data
	{
		pushfront(nd, str, num); // add into the list
		return;
	}
	
	else
	{
		insert(nd->next, str, num);
	}
}


void occurrences(node* &nd, string s) { // find occurrences of characters in a string, put char value pairs into linked list
	
	int num = 0;
	string cha; // the 1 char long string
	
	while (s.length() != 0) // repeat until string is empty
	{
		cha = s.at(0); // character at point 0
		
		while (s.find(cha) != string::npos) // remove all instances of this char from the string
		{	
			num += 1;
			s.erase(s.begin() + s.find(cha));
		}
		
		insert(nd, cha, num); // assign char value pair into linked list
		num = 0;
	}
}


bool sort(node* &nd, bool isSorted) { // sort chars within the numerical list
	
	if (nd -> next == 0)
	{
		return isSorted;
	}

	if (nd->i < nd->next->i) // if a smaller number is in front of a larger number, swap
	{
		// swap the two nodes
		node* temp;
		temp = nd; // set temp value
		nd = nd->next; // swap the data
		temp->next = nd->next;
		nd->next = temp;
		isSorted = false;

	}

	else if (nd->i == nd->next->i) // if numbers are equal, check letters
	{
		if ((nd->s).at(0) > (nd->next->s).at(0)) // if first character of first node is greater than first of next
		{
			// swap the two nodes
			node* temp;
			temp = nd; // set temp value
			nd = nd->next; // swap the data
			temp->next = nd->next;
			nd->next = temp;
			isSorted = false;

		}
	}
	isSorted = sort(nd->next, isSorted); // recurse with next node in list
	return isSorted;
}


node* combine(node* &n1, node* &n2) { // combine two nodes into a root with the original two as left and right children
	
	int num = (n1->i) + (n2->i); // add the two nodes numbers
	
	node* combined = NewNode(n1->s, num);

	(combined->s) += n2->s; // add the chars together into a string


	// add node children to tree in correct place
	if (n1->i < n2->i) // n1 is smaller number, put on left
	{
		combined->left = n1; // make node children
		combined->right = n2;
	}
	
	else if (n1->i > n2->i) // n2 is smaller number, put on left
	{
		combined->left = n2;
		combined->right = n1;
	}
	
	else if (n1->i == n2->i) // if numbers are equal higher in alpha order goes on left
	{
		if ((n1->s).at(0) < (n2->s).at(0)) // n1 is higher letter
		{
			combined->left = n1;
			combined->right = n2;
		}
		
		else // n2 is higher letter
		{
			combined->left = n2;
			combined->right = n1;
		}
	}
	
	n1 = 0;
	n2 = 0;
	
	return combined;
}


void lastcomb(node* &nd) { // use combine function on last two items in list
	
	if (nd == 0)
	{
		return;
	}
	
	if (nd->next->next == 0) // if at the end, combine last 2 nodes
	{
		nd = combine(nd, nd->next);
	
		return;
	}

	lastcomb(nd->next); // recurse if not at the end

}


void hashtable(node* &nd, string str, vector <string> &v) { // Make table of letter values
	
	string complete = "";
  
    if (nd == 0)
	{
        return; 
	}

    else 
	{
		if ((nd->s).size() == 1) // print value if the node has only one letter
		{
        	//cout << nd->s << ": " << str << endl; // delete later
        	complete = (nd->s) + ": " + str;
        	v.push_back(complete);
        	complete = "";
		}
	
		hashtable(nd->left, str + "0", v); 
    	hashtable(nd->right, str + "1", v); 
	}
} 


void processvec(vector <string> &v) {
	
	bool sorted; // sort by lowest length
	string t;
		
		do
		{
			sorted = true;
			
			for (unsigned int x = 0; x < v.size()-1; x++) {
				if ((v[x]).size() > (v[x+1]).size()) // compare by length of strings, so lower binary goes first
				{
					t = v[x]; // set temp value
					v[x] = v[x+1]; // swap the two numbers
					v[x+1] = t;
					
					sorted = false;
				}
			}
		} while (!sorted);
	
	for (unsigned int x = 0; x < v.size(); x++) // print the vector
	{
		cout << v[x] << endl;
	}
}


int main() {
	
	string st; // initial string
	getline(cin, st);
	
	node* nd = 0;
	
	occurrences(nd, st);

	bool sorted = false; // setup bool

	while (!sorted) { // repeat until all sorts are made
		sorted = true;
		sorted = sort(nd, sorted); // call function, while statement repeats if it returns false
	}

	sorted = false;

	while (nd->next != 0)
	{
		lastcomb(nd);

		// sort the list again
		while (!sorted)
		{
			sorted = true;
			sorted = sort(nd, sorted); // call function, while statement repeats if it returns false
		}

		sorted = false;

	}
	
	// make vector for hash table
	vector <string> vec;

	hashtable(nd, "", vec);
	
	processvec(vec);

	return 0;
	
}
