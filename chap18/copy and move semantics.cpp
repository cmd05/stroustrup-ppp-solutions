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
	X x1 = bycopy(); // copy-elison by default (mc when -fno-elide-constructors is passed)


	f(x1); // cc (always)
	f(std::move(x1)); // mc (always)

	X x2{1};
	x2 = bycopy(); // ma (always)
	x2 = x1; // ca
	X x3 = x1; // cc
}