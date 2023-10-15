#include <iostream>
#include <math.h>
#include <complex>
#include "../includes/Matrix.h"
#include "../includes/MatrixIO.h"

using namespace Numeric_lib;

int main() {
/*	// Print the size of a char, a short, an int, a long, a float, a double, an int*,
	// and a double* (use sizeof, not <limits>)
	std::cout << sizeof(char) << '\t' << sizeof(short) << '\t' << sizeof(int) << '\t' << sizeof(long) << '\t'
			  << sizeof(float) << '\t' << sizeof(double) << '\t' << sizeof(int*) << '\t' << sizeof(double*) << '\n';
	Matrix<int> a(10); Matrix<int> b(100); Matrix<double> c(10); Matrix<int,2> d(10,10); Matrix<int,3> e(10,10,10);
	std::cout << sizeof(a) << '\t' << sizeof(b) << '\t' << sizeof(c) << '\t' << sizeof(d) << '\t' << sizeof(e) << '\n';
	std::cout << a.size() << '\t' << b.size() << '\t' << c.size() << '\t' << d.size() << '\t' << e.size() << '\n';

	std::cout << "Enter int (sqrt): ";
	for(int x = 0; std::cin >> x;) {
		// int errno = 0;
		double res = sqrt(x);
		if(errno != 0) {
			std::cout << "no square root\n";
			break;
		}
		else
			std::cout << "sqrt of " << x << " is " << res << '\n';
		std::cout << "Enter int (sqrt): ";
	}

	Matrix<double> mt1(10);
	std::cin >> mt1;
	std::cout << mt1 << '\n';

	// n rows, m cols
	int n, m;
	std::cout << "Enter n (r) and m (c): ";
	std::cin >> n;
	std::cin >> m;

	Matrix<int, 2> mult(n, m);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			mult(i, j) = i*j;

	std::cout << mult;

	Matrix<std::complex<double>> mt2(10);
	std::cin >> mt2;
	std::cout << mt2 << '\n';*/

	Matrix<int, 2> mt3(2,3);
	std::cin >> mt3;
	std::cout << mt3;
}