// 11. Design and implement a counted_ptr<T> that is a type that holds a
// pointer to an object of type T and a pointer to a “use count” (an int)
// shared by all counted pointers to the same object of type T. The use
// count should hold the number of counted pointers pointing to a given
// T. Let the counted_ptr’s constructor allocate a T object and a use
// count on the free store. Let counted_ptr’s constructor take an
// argument to be used as the initial value of the T elements. When the
// last counted_ptr for a T is destroyed, counted_ptr’s destructor
// should delete the T. Give the counted_ptr operations that allow us
// to use it as a pointer. This is an example of a “smart pointer” used to
// ensure that an object doesn’t get destroyed until after its last user has
// stopped using it. Write a set of test cases for counted_ptr using it as
// an argument in calls, container elements, etc.

// Similar to shared_ptr

#include <iostream>
#include <vector>
#include "counted_ptr.h"

template<typename T>
void f(counted_ptr<T> c) {
	counted_ptr<T> cp {c};
}

int main() {
	char c = 'c';
	char d = 'd';

	counted_ptr<char> cp1 {c};
	counted_ptr<char> cp2 = cp1;


	counted_ptr<char> cp3 {d};
	counted_ptr<char> cp4 {cp3};

	cp3 = cp1;
	cp2 = cp4;

	f(cp1);

	std::vector<counted_ptr<char>> v {cp1};
	std::cout << cp1.get_count() << "\t" << cp4.get_count();
}