#include <iostream>
#include <string>
#include <type_traits>

#include "vector.h"
#include "VectorIO.h"
#include "Book.h"
#include "Debug.h"

int main() {
	vector<int> v{1,2,3};
	vector<int> v2;

	VectorIO vio {&v}; // compile with c++20 for CTAD (-std=c++2a)
	std::cout << vio;

// 	v2 = v;
// 	v2.push_back(8);
//     v2.push_back(4);
//     v2.push_back(5);

// //	v2.resize(10, 0);
//     print_vdt(v2);
//     print_vc(v2);

//     v2.insert(v2.begin()+2, 64);
// 	print_vc(v2);

//     v2.erase(v2.begin()+2);
//     print_vc(v2);

// //	print_vc(v);

// 	print('\t');

// 	Book b {"The War of the Worlds", 0};
// 	b.add_from_record("chapters.txt");
// 	//	b.chapters.resize(100); // will give an error

// //	std::cout << b;
}