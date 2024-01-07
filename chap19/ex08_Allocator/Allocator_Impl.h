#pragma once
#include <cstdlib>
#include "Allocator.h"

template<typename T>
T* Allocator<T>::allocate(int n) const {
	return (T*) malloc(n * sizeof(T)); // convert void* to T*
}

template<typename T>
void Allocator<T>::construct(T* p, const T& val) const {
	// placement new
	// new (<address>) <type>(<initializer>)
	// (https://en.cppreference.com/w/cpp/language/new#Placement_new)
	new(p) T{val};
}

template<typename T>
void Allocator<T>::destroy(T* p) const {
	// explicit call to destructor
	p->~T();
}

template<typename T>
void Allocator<T>::deallocate(T* p, int n) const {
	free(p);
}