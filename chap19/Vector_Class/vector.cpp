#include <algorithm>
#include "vector.h"

vector::vector(): sz{0}, elem{0}, space{0} {}

vector::vector(int s): sz{s}, elem{new double[s]} { for(int i = 0; i < s; i++) elem[i] = 0; }

vector::vector(std::initializer_list<double> lst): sz{lst.size()}, elem{new double[sz]} {
	std::copy(lst.begin(), lst.end(), elem);
}

// copy constructor
vector::vector(const vector& arg): sz{arg.sz}, elem{new double[sz]} {
	for(int i = 0; i < sz; i++) elem[i] = arg.elem[i];
}

// copy assignment 
vector& vector::operator=(const vector& arg) {
	// we create a copy of a before deleting to account for self-assignment
	double* p = new double[arg.sz];
	sz = arg.sz;
	for(int i = 0; i < arg.sz; i++) p[i] = arg.elem[i];
	delete[] elem;
	elem = p;
	return *this; // for chaining
}

// move constructor
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

double& vector::operator[] (int n) { return elem[n]; } // assignment
double vector::operator[] (int n) const { return elem[n]; }

// destructor
vector::~vector() { delete[] elem; }


// ----------------------------- INTERFACE FUNCTIONS ---------------------------------------------

void vector::reserve(int new_alloc) {
	if(new_alloc <= space) return;
	double* p = new double[new_alloc];
	for(int i = 0; i < sz; i++) p[i] = elem[i];
	delete[] elem;
	elem = p;
	space = new_alloc;
}

int vector::capacity() const { return space; }

void vector::resize(int new_size) {
	reserve(new_size);
	for(int i = sz; i < new_size; i++) elem[i] = 0;
	sz = new_size;
}

void vector::push_back(double d) {
	if(space == 0)
		reserve(8);
	else if(sz == space) 
		reserve(2*space)

	elem[sz] = d;
	++sz;
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
