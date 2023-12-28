#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct X { // simple test class
    int val;

    void out(const string& s, int nv) {
        cerr << this << "->" << s << ": " << val << " (" << nv << ")\n";
    }

    X() {
        out("X()", 0);
        val = 0;
    } // default constructor

    X(int v) {
        out("X(int)", v);
        val = v;
    }

    X(const X& x) {
        out("X(X&) ", x.val);
        val = x.val;
    } // copy constructor

    X& operator=(const X& a) // copy assignment
    {
        out("X::operator=()", a.val);
        val = a.val;
        return*this;
    }
	
	~X() {
        out("~X()", 0);
    } // destructor
};

X glob_x(2); // a global variable

X copy(X a) {std::cout << "{" << &a << "}\n";  return a; }

X copy2(X a) { X aa = a; return aa; }

X& ref_to(X& a) { return a; }

X* make(int i) { X a(i); return new X(a); }

struct XX { X a {111}; X b {222}; };

int main() {
    X loc {4}; // local variable
    X loc2 = loc; // copy construction
    loc = X {5}; // copy assignment

    /**
     * 1. construct function argument by copy constructor
     * 2. construct return value by copy constructor
     * 3. assign value to left hand expression by copy assignment
     * 4. destroy return value by its destructor
     * 5. destroy the function argument by its destructor
     */ 
    std::cout << "***\n";
    loc2 = copy(loc); // call by value and return
    std::cout << "***\n";

    loc2 = copy2(loc);
    X loc3 {6};

    std::cout << "^^^^^\n";
    X& r = ref_to(loc); // call by reference and return
    std::cout << "^^^^^\n";
    
    delete make(7);
    std::cout << "!!!!!\n";
    delete make(8);
    std::cout << "!!!!!\n";

    vector <X> v(4); // default values
    XX loc4;
    std::cout << "!!!!!\n";
    X* p = new X {9}; // an X on the free store
    delete p;
    std::cout << "!!!!!\n";
    X* pp = new X[5]; // an array of Xs on the free store
    delete[] pp;
    std::cout << "!!!!!\n";
}