// The function arguments f for a.apply(f) and apply(f,a) are different. Write
// a triple() function for each and use each to triple the elements of an array
// { 1 2 3 4 5 }. Define a single triple() function that can be used for both
// a.apply(triple) and apply(triple,a). Explain why it could be a bad idea to
// write every function to be used by apply() that way.

// Do exercise 1 again, but with function objects, rather than functions.
// Hint: Matrix.h contains examples

#include "../includes/Matrix.h"
#include "../includes/MatrixIO.h"
using namespace Numeric_lib;

int triple(int x) { return x*3; }
// void triple(int& x) { x*=3; }

int main() {
	int arr[] = {1,2,3,4,5};
	Matrix<int> a {arr};
	a.apply(triple);
	Matrix<int> b = apply(triple, a);
	std::cout << a << "\t" << b;

}