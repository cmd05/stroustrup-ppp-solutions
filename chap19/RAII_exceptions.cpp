#include <iostream>

// this is how std::array works. no need of defining copy constructors / assignment
// arrays will be deep copied when placed in class/struct
struct Err {};

struct X {
    X() { std::cout << "X()"; }
    ~X() { std::cout << "~X()"; }
};

struct A {
    X* elem;
    int sz = 5;

    A() {
        std::cout << "A()";
        elem = new X[sz];
        // throw Err{}; // incomplete constructor does not 
    }

    const X& at(int n) const {
        if(n < 0 || n > sz) throw Err{};
        return elem[n];
    } 

    ~A() {
        std::cout << "~A()";
        delete[] elem;
    }
};

void f() {
    try {
        A a;
    } catch(...) {
        std::cout << "caught,a ";
    }
    throw Err{};
    int x = 5;
}

// Catching exceptions to avoid memory leaks
X f2() {
    // // First Approach

    A* a = new A;
    X x;

    try {
        x = a->at(-1); // throws
    } catch(...) {
        delete a; // free memory before throwing
        throw; // rethrow that error
    }

    // ... do something with x (operations that won't throw)
    
    delete a; // finally free memory
    return x;

    
    // // Second - Alternative approach

    // try {
    //     A* a = new A;
    //     X x;
    //     x = a->at(-1); // throws
        
    //     // ... do operations on x (can throw)
        
    //     delete a; // free memory before return
    //     return x;
    // } catch(...) {
    //     delete a; // free memory before throwing
    //     throw; // rethrow that error
    // }
}

// Catching exceptions when returning a pointer
A* f3() {
    A* a = new A;

    try {
        X x = a->at(-1); // throws

        // any operations which may or may not throw

        return a;
    } catch(...) {
        delete a; // free memory before throwing
        throw;
    }
} // caller has to manually delete returned A*

int main() {
    try {
        f();
    } catch(Err e) { // if Err is uncaught ~A() is not called (memory leak happens)
        std::cout << "caught,f ";
    }

    std::cout << "main";
}