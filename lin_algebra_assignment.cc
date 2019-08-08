// Mr. Arkiletian ICTP 12
// Simultaneous linear equation assignment (2 team members)
// Solved using the STL generic vector container class 


#include <iostream>
#include <vector>
#include <cmath> // for pow function

using namespace std;

typedef vector <double> Dvector;
typedef vector <Dvector> Dmatrix;

// Prototypes (variable names included, but not needed)
// DO NOT change any prototypes!! NO other functions allowed.

Dmatrix GetA(); 
// gets the matrix A from the user and returns it

Dvector Getb(const int &siz); 
// gets the vector b from the user and returns it

void Display(const Dvector &xvect); 
// displays the contents of vector xvect

void Display(const Dmatrix &Amat); 
// displays the contents of matrix Amat (Note: Display function is overloaded)

Dvector Solvex(const Dmatrix &Amat, const Dvector &bvect);
// Solves for systems of linear equations in the form Ax=b using cramer's rule 

double Det(const Dmatrix &Amat);
// returns the Determinant of matrix Amat using a recursive algorithm
// base case is 2x2 matrix 

Dmatrix Replace(Dmatrix Rmat, const int col, const Dvector &bvect);
// Replaces the column 'col' in Rmat with bvect and returns Rmat

Dmatrix Minor(const Dmatrix &Amat, const int col);
// Gets the Minor matrix of Amat by crossing out the first row and 
// column 'col' then returns that smaller matrix


//-------------------------------------------
int main(){

Dmatrix A;     
Dvector b,x;

A=GetA();
Display(A);
b=Getb(A.size());

x=Solvex(A,b);

Display(x);

return(0);
}
//-------------------------------------------

Dmatrix GetA() {
	Dmatrix mat;
	int length;
	double temp;
	cin >> length;
	//asks for inputs based on length givin to make the matrix
	for (int i=0; i<length; i++) {
		Dvector v;
		for (int j=0; j<length; j++) {
			cin >> temp;
			v.push_back(temp);
		}
		mat.push_back(v);
	}
	return mat;
}
//displays the Dmatrix given
void Display(const Dmatrix &Amat) {
	cout << endl;
	for (unsigned int i=0; i<Amat.size(); i++) {
		for (unsigned int j=0; j<Amat.size(); j++) {
			cout << Amat[i][j] << " ";
		}
		cout<< endl;
	}
	cout << endl;
}

//this display is for after Solvex has run to dispay the answer
void Display(const Dvector &xvect) {
	for (unsigned int i=0; i<xvect.size(); i++) {
		cout << xvect[i] << " ";
	}
	cout << endl;
}

//gets the values of B
Dvector Getb(const int &siz) {
    
    Dvector vec;
    double x;
    
    for (int i = 0; i < siz; i++)
    {
        cin >> x;
        vec.push_back(x);
    }
    
    return vec;
}
//runs Replace and Det in order to get the answer
Dvector Solvex(const Dmatrix &Amat, const Dvector &bvect) {
    
    Dvector x;
    double a = Det(Amat); // original determinant
    for (unsigned int i = 0; i < bvect.size(); i++)
    {
        Dmatrix repl = Replace(Amat, i, bvect); // matrix with replaced b
        double a1 = Det(repl); // determinant of different versions
        x.push_back(a1/a);
    }
    return x;
}
//finds the determinant
double Det(const Dmatrix &Amat) {
	double save=0; //saved value
	double norp; //is the number negative or positive (-1 or 1)
	double cross; //where the 'crosshair' goes
	double determin; //saves the answer from recursion
	if (Amat.size()>2) { //runs if Amat is not a 2x2
		for (unsigned int i=0; i<Amat.size(); i++) {
			if (i%2==0) { norp=1; } //finds if value is negative or positive, asigns value based on that
			else { norp=-1; }
			cross=Amat[0][i];
			determin=Det(Minor(Amat,i));
			save= save + (norp*cross*determin); //does the equation to calculate answer
		}
		
	} //runs if Amat is a 2x2
	else if (Amat.size()==2) {
		save=(Amat[0][0]*Amat[1][1])-(Amat[0][1]*Amat[1][0]); // criss cross of 2x2
	}
	
	return save;
	// Amat.size can never be less then 2
	}

//replaces one line of the matrix with bvect
Dmatrix Replace(Dmatrix Rmat, const int col, const Dvector &bvect) {
	Dmatrix neww;
	for (unsigned int i=0; i<Rmat.size(); i++) {
		Dvector temp;
		for (unsigned int j=0; j<Rmat.size(); j++) {
			if (j!=col) {
				temp.push_back(Rmat[i][j]);
			}
			else {
				temp.push_back(bvect[i]);
			}
		
		}
		
		neww.push_back(temp);
	}
	
	return neww;
}






//solves the minor
Dmatrix Minor(const Dmatrix &Amat, const int col) {
	Dmatrix neww;
	//remove top line
	for (unsigned int i=1; i<Amat.size(); i++) {
		Dvector temp;
		for (unsigned int j=0; j<Amat.size(); j++) {
			//remove middle line
			if (j!=col) {
				temp.push_back(Amat[i][j]);
			}
		}
		neww.push_back(temp);
	}
	return neww;
}

