#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "A()\n"; }
    ~A() { cout << "~A()\n"; }
};

class A_v {
public:
    A_v() { cout << "A_v()\n"; }
    virtual ~A_v() { cout << "~A_v()\n"; }
};

class B : public A {
public:
    B() { cout << "B()\n"; }
    ~B() { cout << "~B()\n"; }
};

class B_v : public A_v {
public:
    B_v() { cout << "B_v()\n"; }
    ~B_v() { cout << "~B_v()\n"; }
};


int main() {
    A* b = new B{}; 
    delete b;

    std::cout << "\n\n";
    
    A_v* b_v = new B_v{}; 
    delete b_v;

    return 0;
}