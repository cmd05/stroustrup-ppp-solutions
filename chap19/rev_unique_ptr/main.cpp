#include <iostream>
#include <memory>
#include "unique_ptr.h"

struct X {
    X() { std::cout << "X()"; }
    ~X() { std::cout << "~X()"; }
};

int main() {
    unique_ptr p {new X}; // new X[n] will give UB
    // std::unique_ptr<X[]> p {new X[2]}; // ok, no memory leak
    p.reset(new X);
}