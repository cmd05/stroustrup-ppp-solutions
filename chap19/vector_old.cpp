#include <algorithm>
#include <memory>
#include "vector.h"

vector::vector(): sz{0}, elem{nullptr}, space{0} {}
vector::vector(int s): sz{s}, elem{alloc.allocate(sz)} {}

vector::vector(std::initializer_list<T> lst): sz{lst.size()}, elem{alloc.allocate(sz)} {
	std::uninitialized_copy(lst.begin(), lst.end(), this->elem);
}

// copy constructor
template<typename T, typename A>
vector::vector(const vector& arg): sz{arg.sz}, elem{alloc.allocate(sz)} {
	uninitialized_copy(arg.elem, &arg.elem[this–>sz], this–>elem);
	// for(int i = 0; i < sz; i++) elem[i] = arg.elem[i];
}

/**
 * Allocate memory for copy
 * Copy the elements
 * Delete the old allocation
 * Set the sz, elem and space to the new values
 */
vector& vector::operator=(const vector& a) {
	if(this == &a) return *this;

	if(a.sz <= space) {
		for(int i = 0; i < a.sz; i++) elem[i] = a.elem[i];
		sz = a.sz;
		return *this;
	}

	double* p = new double[a.sz];
	for(int i = 0; i < a.sz; i++) p[i] = a.elem[i];
	delete[] elem;
	elem = p;
	space = sz = a.sz;
	return *this;
}


// move constructor
// moves rvalue to lvalue instead of creating a new object

vector::vector(vector&& a): sz{a.sz}, elem{a.elem} {
	a.sz = 0;
	a.elem = nullptr;
}

// move assignment
vector& vector::operator=(vector&& a) {
	delete[] elem;
	elem = a.elem;
	sz = a.sz;
	a.elem = nullptr;
	a.sz = 0;
	return *this; // chaining
}

void vector::set(int index, double v) { elem[index] = v; }
double vector::get(int i) const { return elem[i]; }
int vector::size() const { return sz; }

template<typename T, typename A>
T& vector::at(int n) const {
	if(n < 0 || nz >= sz) throw out_of_range();
	return elem[n];
} 

template<typename T, typename A>
T vector::at(int n) const {
	if(n < 0 || nz >= sz) throw out_of_range();
	return elem[n];
}

template<typename T, typename A>
T& vector::operator[] (int n) const { return elem[n]; }

template<typename T, typename A>
T vector::operator[] (int n) const { return elem[n]; }

// destructor
vector::~vector() { delete[] elem; }


// ----------------------------- INTERFACE FUNCTIONS ---------------------------------------------

/// reserve() without exception safety 
// template<typename T, typename A>
// void vector<T,A>::reserve(int new_alloc) {
// 	if(new_alloc <= space) return;

// 	T* p = alloc.allocate(new_alloc); // allocate new memory
// 	for(int i = 0; i < sz; i++) alloc.construct(&p[i], elem[i]); // copy to new memory
// 	for(int i = 0; i < sz; i++) alloc.destroy(&elem[i]); // call destructor of elem[i] of type T
// 	alloc.deallocate(elem, space); // deallocate elem

// 	elem = p;
// 	space = new_alloc;
// }

// using uniq_ptr
// template<typename T, typename A> {
// 	if(new_alloc <= space) return;
// 	std::unique_ptr<T> p = alloc.allocate(new_alloc);

// 	for(int i = 0; i < sz; i++) alloc.construct(&p[i], this->elem[i]);
// 	for(int i = 0; i < sz; i++) alloc.destroy(&p[i], this->elem[i]);

// 	alloc.deallocate(this->elem); // still needed to deallocate
	
// 	elem = p;
// 	space = new_alloc;
// }

// using vector_base
template<typename T, typename A>
void vector<T,A>::reserve(int new_alloc) {
	if(new_alloc <= space) return;
	Vector_Base vb{alloc, new_alloc};

	// uninitialized_copy(b.elem, &b.elem[this–>sz], this–>elem);
	for(int i = 0; i < sz; i++) 
		// even if construct() throws exception ~vb() is called
		alloc.construct(&vb.elem[i], this->elem[i]); // copy to new memory
	
	for(int i = 0; i < sz; i++) 
		alloc.destroy(&this->elem[i]); // call destructor of elem[i] of type T

	swap<Vector_Base<T,A>>(*this, vb);
}


int vector::capacity() const { return space; }

template<typename T, typename A>
void vector::resize(int new_size, T val = T()) {
	reserve(new_size);
	for(int i = sz; i < new_size; i++) alloc.construct(&elem[i], val);
	for(int i = new_size; i < sz; i++) alloc.destroy(&elem[i]); // if new_size < sz

	sz = new_size;
}

void vector::push_back(double d) {
	if(space == 0)
		reserve(8);
	else if(sz == space) 
		reserve(2*space);

	elem[sz] = d;
	++sz;
}