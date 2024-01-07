#include <iostream>
#include <string>
#include "vector.h"
#include "vector_impl.h"
#include "Book.h"
#include "Debug.h"

int main() {
	vector<int> v{1,2,3};
	vector<int> v2;

	v2 = v;
	v2.push_back(8);
	v2.resize(10);

	print_vc(v2);
	print_vc(v);

	print('\t');

	Book b {"The War of the Worlds", 0};
	b.add_from_record("chapters.txt");
	//	b.chapters.resize(100); // will give an error

	std::cout << b;
}