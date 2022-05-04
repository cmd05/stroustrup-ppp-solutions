#pragma once
#include <memory>

template<typename T, typename A>
struct Vector_Base {
	A alloc;
	T* elem;
	int sz;
	int space;

	Vector_Base() {}
	Vector_Base(const A& a, int n):
		alloc{a}, elem{alloc.allocate(n)}, sz{n}, space{n} {}
	~Vector_Base() {
		for(int i = 0; i < sz; i++) 
			alloc.destroy(&this->elem[i]); // call destructor of elem[i] of type T

		alloc.deallocate(elem, space); 
	}
};