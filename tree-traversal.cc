#include <iostream>
#include <queue>

// :: is a scope resolution operator, used for things like node::node and std::cout

using namespace std;

struct node {
	int i;
	node* left;
	node* right;

};


node* NewNode(int s) { // add a node to the list with data s
	node* np = new node;
	np->i = s;
	np->left = 0;
	np->right = 0;
	return np;
}


void insert(node* &root, int x) { // insert nodes with ints in the tree in the right places
	
	if (root == 0) // if current node is empty
	{
		root = NewNode(x); // assign i to first node
	}
	
	else if (x < root->i) // if i is less than node data
	{
		insert(root->left, x); // recurse down to the left
	}
	
	else // if i is greater than node data
	{
		insert(root->right, x); // recurse down to the right
	}
	
}


void inOrder(node* nd) { // left, print, right: returns 2, 3, 4, 6, 7, 8
	
	if (nd->left != 0) // check for left child
	{
		inOrder(nd->left); // recurse the function with the left child
	}
	
	cout << nd->i << " "; // print current node
	
	if (nd->right != 0) // check for right child
	{
		inOrder(nd->right); // recurse the function with the right child
	}
	
}


void preOrder(node* nd) { // print, left, right: returns 6, 3, 2, 4, 8, 7
	
	cout << nd->i << " "; // print current node
	
	if (nd->left != 0) // check for left child
	{
		preOrder(nd->left); // recurse the function with the left child
	}
	 
	if (nd->right != 0) // check for right child
	{
		preOrder(nd->right); // recurse the function with the right child
	}
	
}


void postOrder(node* nd) { // left, right, print: returns 2, 4, 3, 7, 8, 6
	
	if (nd->left != 0) // check for left child
	{
		postOrder(nd->left); // recurse the function with the left child
	}
	
	if (nd->right != 0) // check for right child
	{
		postOrder(nd->right); // recurse the function with the right child
	}
	
	cout << nd->i << " "; // print current node
	
}


void breadth(node* nd, queue <node*> &q) { // left to right, top to bottom: returns 6, 3, 8, 2, 4, 7
	
	// queues work in a first in, first out (fifo) system. imagine a bus stop lineup; first in line is first on the bus
	
	if (nd->left != 0) // check for left child
	{
		q.push(nd->left); // add left to queue
	}
	
	if (nd->right != 0) // check for right child
	{
		q.push(nd->right); // add right to queue
	}
	
	cout << (q.front())->i << " "; // print frontmost
	q.pop(); // remove frontmost
	
	if (!q.empty()) // if there are still nodes in the queue
	{
		breadth(q.front(), q); // recurse with new frontmost
	}
	
}


void lfree(node* nd) { // delete nodes recursively to avoid memory leaks
	
	if (nd != 0) // check if tree is empty
	{
		lfree(nd->left); // recurse to the left
		lfree(nd->right); // recurse to the right
		
		delete nd; // delete node
		nd = 0; // set node to 0 to avoid leaks
	}
	
}


int main() {
	
	node* root = NewNode(6); // set up binary tree, each node has two child nodes
	
	int iarray[5] = {3, 8, 2, 4, 7};
	
	for (int n = 0; n < 5; n++)
	{
		insert(root, iarray[n]);
	}
	
	cout << "In order: ";
	inOrder(root);
	
	cout << endl << "Pre order: ";
	preOrder(root);
	
	cout << endl << "Post order: ";
	postOrder(root);
	
	
	queue <node*> q; // setting up queue for breadth sort
	q.push(root); // put first node in queue
	
	cout << endl << "Breadth first: ";
	breadth(root, q);
	
	lfree(root);
	
	return 0;
	
}
