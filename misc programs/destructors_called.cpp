#include <iostream>
#include <list>

int called = 0;

struct X {
    ~X() { called++; }
};

int main() {
    std::list<X> larger(8);
    std::list<X> smaller(5);
    larger = smaller;
    std::cout << called;
}