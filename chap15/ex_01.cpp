#include <iostream>

int fac(int n) { return n > 1 ? n*fac(n-1) : 1; }

int main() {
    for(int i = 1; i <= 20; i++) std::cout << fac(i) << '\n';
}

/**
 * Using iterative method is more clear and obvious
 */