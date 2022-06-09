// // 10. Implement a simple unique_ptr supporting only a constructor,
// // destructor, –>, *, and release(). In particular, don't try to implement
// // an assignment or a copy constructor.

#include <iostream>
#include <fstream>
#include <string>
#include "unique_ptr.h"

struct X {
	X(): name{"John Doe"}, age{0} {}
	X(std::string n, int a): name{n}, age{a} {}

	std::string name;
	int age;
};

std::ostream& operator<<(std::ostream& os, const X& x) {
	return os << "X: " << x.name;
}


int main() {
	X x{"cmd", 18};
	unique_ptr<X> u{new X{"cmd05", 17}};

	std::cout << *u << "\t(age " << u->age << ")";
}