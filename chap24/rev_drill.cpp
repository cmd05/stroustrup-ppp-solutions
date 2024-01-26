#include <iostream>
#include <complex>
#include "../includes/graphics/Matrix.h"
using namespace Numeric_lib;

int main() {
    std::cout << sizeof(char) << ' ' << sizeof(short) << ' ' 
              << sizeof(int) << ' ' << sizeof(long) << ' '
              << sizeof(float) << ' ' << sizeof(double) << ' '
              << sizeof(int*) << ' ' << sizeof(double*) << '\n';
    
    std::cout << sizeof(Matrix<int>(10)) << ' ' << sizeof(Matrix<int>(100)) << ' ' << sizeof(Matrix<double>(10)) << ' ' <<  sizeof(Matrix<int,2>(10,10))
              << ' ' << sizeof(Matrix<int,3>(10,10,10)) << '\n';

    std::complex<double> c;
    std::cin >> c;
    std::cout << c.real() << " + i(" << c.imag() << ")\n";

    std::cout << "sqrts:\n";
    for(int i; std::cin >> i;) {
        errno = 0;
        double res = sqrt(i);

        if(errno) std::cout << "error performing sqrt(" << i << ")\n";
        else std::cout << res << '\n';
    }
}