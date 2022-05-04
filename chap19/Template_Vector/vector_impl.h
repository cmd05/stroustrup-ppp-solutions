#pragma once
#include <algorithm>
#include <memory>
#include "vector.h"
#include "Vector_Base.h"

// --------------------------------------------------------------------------

// ---------------------------------------

template<typename T, typename A>
vector<T,A>::vector(): sz{0}, elem{nullptr}, space{0} {}

template<typename T, typename A>
vector<T,A>::vector(int s): sz{s}, elem{alloc.allocate(sz)} {}

template<typename T, typename A>
vector<T,A>::vector(std::initializer_list<T> lst): sz(lst.size()), elem{alloc.allocate(sz)} {
	std::uninitialized_copy(lst.begin(), lst.end(), this->elem);
}

template<typename T, typename A>
vector<T,A>::~vector() { delete[] elem; }

// ---------------------------------------

template<typename T, typename A>
vector<T,A>::vector(const vector<T,A>& arg): sz{arg.sz}, elem{alloc.allocate(sz)} {
	std::uninitialized_copy(arg.elem, &arg.elem[this->sz], this->elem);
	// for(int i = 0; i < sz; i++) elem[i] = arg.elem[i];
}

template<typename T, typename A>
vector<T,A>& vector<T,A>::operator=(const vector<T,A>& a) {
	if(this == &a) return *this;

	if(a.sz <= space) {
		std::copy(a.elem, &a.elem[a.sz], this->elem);
		// for(int i = 0; i < a.sz; i++) elem[i] = a.elem[i];
		sz = a.sz;
		return *this;
	}

	Vector_Base<T,A> vb{alloc, a.sz};
	for(int i = 0; i < a.sz; i++) alloc.construct(&vb[i], a.elem[i]);
	swap_v_vb(this, &vb);

	return *this;
}

// ---------------------------------------

// move constructor
template<typename T, typename A>
vector<T,A>::vector(vector<T,A>&& a): sz{a.sz}, elem{a.elem} {
	// Prevent destructor from freeing memory multiple times
	a.sz = 0;
	a.elem = nullptr;
}

// move assignment
template<typename T, typename A>
vector<T,A>& vector<T,A>::operator=(vector<T,A>&& a) {
	delete_elem();

	elem = a.elem;
	sz = a.sz;

	a.elem = nullptr;
	a.sz = 0;

	return *this; // chaining
}

// --------------------------------------------------------------------------

template<typename T, typename A>
void swap_v_vb(vector<T,A>* v, Vector_Base<T,A>* vb) {
	std::swap(v.elem, vb.elem);
	std::swap(v.sz, vb.sz);
	std::swap(v.space, vb.space);
	std::swap(v.alloc, vb.alloc);
}

template<typename T, typename A>
void vector<T,A>::delete_elem() {
	for(int i = 0; i < sz; i++) 
		alloc.destroy(&this->elem[i]);

	alloc.deallocate(elem, space); 
}

// --------------------------------------------------------------------------

template<typename T, typename A>
int vector<T,A>::size() const { return sz; }

template<typename T, typename A>
int vector<T,A>::capacity() const { return space; }

// --------------------------------------------------------------------------

template<typename T, typename A>
void vector<T,A>::set(int index, T v) { elem[index] = v; }

template<typename T, typename A>
const T vector<T,A>::get(int i) const { return elem[i]; }

template<typename T, typename A>
T& vector<T,A>::at(int n) {
	if(n < 0 || n >= sz) throw out_of_range();
	return elem[n];
} 

template<typename T, typename A>
T vector<T,A>::at(int n) const {
	if(n < 0 || n >= sz) throw out_of_range();
	return elem[n];
}

template<typename T, typename A>
T& vector<T,A>::operator[] (int n) { return elem[n]; }

template<typename T, typename A>
T vector<T,A>::operator[] (int n) const { return elem[n]; }

// --------------------------------------------------------------------------

template<typename T, typename A>
void vector<T,A>::reserve(int new_alloc) {
	if(new_alloc <= space) return;
	Vector_Base<T,A> vb{alloc, new_alloc};

	// uninitialized_copy(b.elem, &b.elem[this–>sz], this–>elem);
	for(int i = 0; i < sz; i++) 
		// even if construct() throws exception ~vb() is called
		alloc.construct(&vb.elem[i], this->elem[i]); // copy to new memory

	std::swap<Vector_Base<T,A>>(*this, vb);
}

template<typename T, typename A>
void vector<T,A>::resize(int new_size, T val) {
	reserve(new_size);
	for(int i = sz; i < new_size; i++) alloc.construct(&elem[i], val);
	for(int i = new_size; i < sz; i++) alloc.destroy(&elem[i]); // if new_size < sz

	sz = new_size;
}

template<typename T, typename A>
void vector<T,A>::push_back(T val) {
	if(space == 0)
		reserve(8);
	else if(sz == space) 
		reserve(2*space);

	elem[sz] = val;
	++sz;
}