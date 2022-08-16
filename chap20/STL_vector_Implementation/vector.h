#pragma once
#include <algorithm>
#include <memory>
#include <string>
#include <iostream>

#include "Vector_Base.h"

struct out_of_range {
	out_of_range(std::string e): err{e} {}
	std::string what() { return err; }

	std::string err;
};

struct Range_Error : out_of_range {
	int index;
	Range_Error(int i): out_of_range("Range error"), index(i) {}
};

struct Length_Error {};

template<typename T, typename A = std::allocator<T>>
class vector {
public:
	// aliases
	using size_type = unsigned long;
	using value_type = T;
	using iterator = T*;
	using const_iterator = const T*;

	iterator begin() { return elem; }
	const_iterator begin() const { return elem; }
	iterator end() { return &elem[sz]; }
	const_iterator end() const { return &elem[sz]; }
	
	iterator back() { return &elem[sz-1]; }

	vector();

	explicit vector(size_type s, T val = T());
	vector(std::initializer_list<T> lst);
	
	vector(const vector& arg); // copy constructor
	vector& operator=(const vector& arg); // copy assignment
	vector(vector&& a); // move constructor
	vector& operator=(vector&& a); // move assignment
	
	size_type size() const;
	size_type capacity() const;

	T& back() { return elem[sz-1]; }
	T& front() { return elem[0]; }

	T& at(size_type n);
	T at(size_type n) const;

	void set(size_type index, T v);
	const T get(size_type i) const;

	T& operator[](size_type n);
	T operator[](size_type n) const;

	void reserve(size_type new_alloc);
	void resize(size_type new_size, T val = T());
	void push_back(T val);

	iterator insert(iterator p, const T& val);
	iterator erase(iterator p);

	~vector();
private:
	size_type sz;
	T* elem;
	size_type space;
	A alloc;
};

////--------------------------------------------------------------------------------------------------------

// -------- CONSTRUCTORS AND DESTRUCTOR -----------------

template<typename T, typename A>
vector<T,A>::vector(): sz{0}, elem{nullptr}, space{0} {}

template<typename T, typename A>
vector<T,A>::vector(size_type s, T val): sz{s}, space{sz}, elem{alloc.allocate(sz)} {
	for (size_type i = 0; i < sz; i++) alloc.construct(&elem[i], val);
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
	for(size_type i = 0; i < sz; i++)
		alloc.destroy(&elem[i]);

	alloc.deallocate(elem, space); 
}

// ----------------- GET CONTAINER DETAILS -------------------------------

template<typename T, typename A>
typename vector<T,A>::size_type vector<T,A>::size() const { return sz; }

template<typename T, typename A>
typename vector<T,A>::size_type vector<T,A>::capacity() const { return space; }

// ----------------- READ AND WRITE OPERATIONS ---------------------------

// -----------------------------

template<typename T, typename A>
void vector<T,A>::set(size_type index, T v) { elem[index] = v; }

template<typename T, typename A>
const T vector<T,A>::get(size_type i) const { return elem[i]; }


// -----------------------------

template<typename T, typename A>
T& vector<T,A>::at(size_type n) {
	if(n < 0 || n >= sz) throw out_of_range("Out of range");
	return elem[n];
} 

template<typename T, typename A>
T vector<T,A>::at(size_type n) const {
	if(n < 0 || n >= sz) throw out_of_range("Out of range");
	return elem[n];
}

// -----------------------------

template<typename T, typename A>
T& vector<T,A>::operator[] (size_type n) { return elem[n]; }

template<typename T, typename A>
T vector<T,A>::operator[] (size_type n) const { return elem[n]; }

// -------------- SIZE OPERATIONS ------------------------

template<typename T, typename A>
void vector<T,A>::reserve(size_type new_alloc) {
	if(new_alloc <= space) return;
	Vector_Base<T,A> vb{alloc, new_alloc};
	std::uninitialized_copy(elem, &elem[sz], vb.elem);

	swap_v_vb(&vb);
}

template<typename T, typename A>
void vector<T,A>::resize(size_type new_size, T val) {
	if(new_size < 0) throw Length_Error{};

	reserve(new_size);
	for(size_type i = sz; i < new_size; i++) alloc.construct(&elem[i], val);

	// if new_size < sz
	for(size_type i = new_size; i < sz; i++) alloc.destroy(&elem[i]);

	sz = new_size;
}

template<typename T, typename A>
void vector<T,A>::push_back(T val) {
	size_type index = sz;

	if(space == 0)
		reserve(8);
	else if(sz == space) 
		reserve(2*space);

	alloc.construct(&elem[index], val);
	sz = index + 1;
}

template<typename T, typename A>
typename vector<T,A>::iterator vector<T, A>::erase(iterator p) {
	if(p==end()) return p;

	for(iterator pos = p+1; pos != end(); ++pos) {
		*(pos - 1) = *pos;
	}

	alloc.destroy(&*(end()-1));
	sz--;

	return p;
}

template<typename T, typename A>
typename vector<T,A>::iterator vector<T,A>::insert(iterator p, const T& val) {
	size_type index = p - begin();
    size_type old_sz = sz;
    T last_elem = *back();

	if(sz == space) reserve(sz == 0 ? 8 : 2*sz);

    // copy last element to uninitialized space
	alloc.construct(elem + old_sz, last_elem);
	sz++;

	// move elements after p one position to the right
	for(auto pos = &elem[old_sz-1]; pos != &elem[index]; --pos)
        *pos = *(pos - 1);

	iterator pp = begin() + index;
    *(begin() + index) = val;
	return pp;
}