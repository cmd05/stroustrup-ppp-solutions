#pragma once
#include <memory>

template<typename T, typename A>
struct Vector_Base {
	using size_type = unsigned long;
	using value_type = T;
	using iterator = T*;
	using const_iterator = const T*;
	
	A alloc;
	T* elem;
	size_type sz;
	size_type space;

	Vector_Base(): sz{0}, space{0}, elem{nullptr} {}
	Vector_Base(const A& a, size_type n):
		alloc{a}, elem{alloc.allocate(n)}, sz{n}, space{n} {}
	~Vector_Base() {
		for(size_type i = 0; i < sz; i++) 
			alloc.destroy(&this->elem[i]); // call destructor of elem[i] of type T

		alloc.deallocate(elem, space);
	}
};