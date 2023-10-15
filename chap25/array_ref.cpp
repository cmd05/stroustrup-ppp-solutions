#include <iostream>

template<typename T>
class Array_ref {
public:
	Array_ref(T* pp, int s): p{pp}, sz{s} {}

	T& operator[](int n) { return p[n]; }
	const T& operator[](int n) const { return p[n]; }
}