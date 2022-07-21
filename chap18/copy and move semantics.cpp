#include <iostream>

struct X {
	int x;

	explicit X(int s): x{s} {}

	X(const X& arg) {x = arg.x; std::cout << "copy constructor\n"; }
	X& operator=(const  X& arg) {x = arg.x; std::cout << "copy assignment\n"; return *this; }
	X(X&& arg) {x = arg.x; std::cout << "move constructor\n"; }
	X& operator=(X&& arg) {x = arg.x; std::cout << "move assignment\n"; return *this; }
};


X bycopy() {
	X x{9};
	return x;	
}

void f(X arg) {
	std::cout << "f\n";
}

int main() {
	X x1 = bycopy(); // mc (-fno-elide-constructors to disable RVO)

	f(std::move(x1)); // mc

	X x2{1};
	x2 = bycopy(); // ma
	x2 = x1; // ca
	X x3 = x1; // cc
}