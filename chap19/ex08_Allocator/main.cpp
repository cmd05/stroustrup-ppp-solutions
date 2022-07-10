// Implement an allocator (§19.3.7) using the basic allocation functions
// malloc() and free() (§B.11.4). Get vector as defined by the end of
// §19.4 to work for a few simple test cases. Hint: Look up "placement
// new" and "explicit call of destructor" in a complete C++ reference.

#include "vector.h"
#include "vector_impl.h"
#include "Debug.h"

int main() {
	vector<int> v{1,2,3};
	vector<int> v2;

	v2 = v;
	v2.push_back(8);
	v2.resize(10);

	print_vc(v2);
	print_vc(v);
}