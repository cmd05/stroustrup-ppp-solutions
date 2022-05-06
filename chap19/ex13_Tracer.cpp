// Write a Tracer class where its constructor prints a string and its
// destructor prints a string. Give the strings as constructor arguments.
// Use it to see where RAII management objects will do their job (i.e.,
// experiment with Tracers as local objects, member objects, global
// objects, objects allocated by new, etc.). Then add a copy constructor
// and a copy assignment so that you can use Tracer objects to see when
// copying is done.

#include <iostream>
#include <string>

class Tracer {
public:
	Tracer(std::string c, std::string d): c{c}, d{d} {
		std::cout << c << "\n";
	}

	Tracer(Tracer& t): c{t.c}, d{t.d} {
		std::cout << "copy_con" << "\n";
	}

	Tracer& operator=(Tracer& t) {
		c = t.c;
		d = t.d;

		std::cout << "copy_assn" << "\n";
		return *this;
	}

	~Tracer() {
		std::cout << d << "\n";
	}

	std::string c;
	std::string d;
};

Tracer glob{"glob_c", "glob_d"};

struct X {
	Tracer t{"mo_c", "mo_d"};
};

int main() {
	Tracer l {"loc_c", "loc_d"};
	X x{};
	Tracer* t = new Tracer{"new_c", "new_d"};
	*t = l;

	Tracer t2 = l;
}