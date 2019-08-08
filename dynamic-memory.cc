#include <iostream>

using namespace std;

int main() {
	double* pvalue = NULL; // pointer initialized with null
	pvalue = new double; // request memory for the variable
	
	*pvalue = 29494.99; // Store value at allocated address
	cout << "Value of pvalue: " << *pvalue << endl;
	
	delete pvalue; // free up memory
	
	return 0;
	
}
	
	
