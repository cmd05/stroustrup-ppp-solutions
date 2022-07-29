#pragma once
#include <type_traits>

#include "vector.h"

template<typename T>
struct VectorIO {
	VectorIO(vector<T>* v): vec{v} {}
	vector<T>* vec;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, VectorIO<T>& v_io) {
	for(auto i = v_io.vec->begin(); i != v_io.vec->end(); i++)
		os << *i << "\n";
	return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, VectorIO<T>& v_io) {
	for(T val; is >> val;)
		v_io.vec->push_back(val);
	return is;
}
