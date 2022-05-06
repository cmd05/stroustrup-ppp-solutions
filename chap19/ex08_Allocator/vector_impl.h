#pragma once
#include <algorithm>
#include "Allocator.h"
#include "Allocator_Impl.h"
#include "vector.h"
#include "Vector_Base.h"
#include <iostream>

// --------------------------------------------------------------------------

// -------- CONSTRUCTORS AND DESTRUCTOR -----------------

template<typename T, typename A>
vector<T,A>::vector(): sz{0}, elem{nullptr}, space{0} {}

template<typename T, typename A>
vector<T,A>::vector(int s, T val): sz{s}, space{sz}, elem{alloc.allocate(sz)} {
	for (int i = 0; i < sz; i++) alloc.construct(&elem[i], val);
}

template<typename T, typename A>
vector<T,A>::vector(std::initializer_list<T> lst): sz(lst.size()), space{sz}, elem{alloc.allocate(sz)} {
	std::uninitialized_copy(lst.begin(), lst.end(), elem);
}

template<typename T, typename A>
vector<T,A>::~vector() { delete[] elem; }

// --------- COPY OPERATIONS --------------------------

template<typename T, typename A>
vector<T,A>::vector(const vector<T,A>& arg): sz{arg.sz}, space{sz}, elem{alloc.allocate(sz)} {
	std::uninitialized_copy(arg.elem, arg.elem + sz, elem);
}

template<typename T, typename A>
vector<T,A>& vector<T,A>::operator=(const vector<T,A>& a) {
	if(this == &a) return *this;

	if(a.sz <= space) {
		std::copy(a.elem, &a.elem[a.sz], elem);
		sz = a.sz;
		return *this;
	}

	Vector_Base<T,A> vb{alloc, a.sz};

	std::uninitialized_copy(a.elem, a.elem + a.sz, vb.elem);
	swap_v_vb(&vb);

	return *this;
}

// ----------- MOVE OPERATIONS ------------------------

template<typename T, typename A>
vector<T,A>::vector(vector<T,A>&& a): sz{a.sz}, space{sz}, elem{a.elem} {
	// Prevent destructor from freeing memory multiple times
	a.sz = 0;
	a.space = 0;
	a.elem = nullptr;
}

template<typename T, typename A>
vector<T,A>& vector<T,A>::operator=(vector<T,A>&& a) {
	delete_elem();

	elem = a.elem;
	space = sz = a.sz;

	a.elem = nullptr;
	a.space = a.sz = 0;

	return *this;
}

// ------------------- FUNCTIONALITIES ------------------------------

template<typename T, typename A>
void vector<T,A>::swap_v_vb(Vector_Base<T,A>* vb) {
	std::swap(elem, vb->elem);
	std::swap(sz, vb->sz);
	std::swap(space, vb->space);
	std::swap(alloc, vb->alloc);
}

template<typename T, typename A>
void vector<T,A>::delete_elem() {
	for(int i = 0; i < sz; i++)
		alloc.destroy(&elem[i]);

	alloc.deallocate(elem, space); 
}

// ----------------- GET CONTAINER DETAILS -------------------------------

template<typename T, typename A>
int vector<T,A>::size() const { return sz; }

template<typename T, typename A>
int vector<T,A>::capacity() const { return space; }

// ----------------- READ AND WRITE OPERATIONS ---------------------------

// -----------------------------

template<typename T, typename A>
void vector<T,A>::set(int index, T v) { elem[index] = v; }

template<typename T, typename A>
const T vector<T,A>::get(int i) const { return elem[i]; }


// -----------------------------

template<typename T, typename A>
T& vector<T,A>::at(int n) {
	if(n < 0 || n >= sz) throw out_of_range("Out of range");
	return elem[n];
} 

template<typename T, typename A>
T vector<T,A>::at(int n) const {
	if(n < 0 || n >= sz) throw out_of_range("Out of range");
	return elem[n];
}

// -----------------------------

template<typename T, typename A>
T& vector<T,A>::operator[] (int n) { return elem[n]; }

template<typename T, typename A>
T vector<T,A>::operator[] (int n) const { return elem[n]; }

// -------------- SIZE OPERATIONS ------------------------

template<typename T, typename A>
void vector<T,A>::reserve(int new_alloc) {
	if(new_alloc <= space) return;
	Vector_Base<T,A> vb{alloc, new_alloc};
	std::uninitialized_copy(elem, &elem[sz], vb.elem);

	swap_v_vb(&vb);
}

template<typename T, typename A>
void vector<T,A>::resize(int new_size, T val) {
	reserve(new_size);

	for(int i = sz; i < new_size; i++) alloc.construct(&elem[i], val);

	// if new_size < sz
	for(int i = new_size; i < sz; i++) alloc.destroy(&elem[i]);

	sz = new_size;
}

template<typename T, typename A>
void vector<T,A>::push_back(T val) {
	int index = sz;

	if(space == 0)
		reserve(8);
	else if(sz == space) 
		reserve(2*space);

	alloc.construct(&elem[index], val);
	sz = index + 1;
}