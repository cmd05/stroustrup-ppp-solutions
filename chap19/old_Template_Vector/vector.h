#pragma once
#include <memory>
#include <string>
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
	// old implementation!! vector does not actually hold any resources, they are held by vector_base only
	int sz;
	T* elem;
	int space;
	A alloc;
public:
	vector();

	explicit vector(int s, T val = T());
	vector(std::initializer_list<T> lst);
	
	vector(const vector& arg); // copy constructor
	vector& operator=(const vector& arg); // copy assignment
	vector(vector&& a); // move constructor
	vector& operator=(vector&& a); // move assignment
	
	int size() const;
	int capacity() const;

	void swap_v_vb(Vector_Base<T,A>* vb);
	void delete_elem();

	T& at(int n);
	T at(int n) const;

	void set(int index, T v);
	const T get(int i) const;

	T& operator[](int n);
	T operator[](int n) const;

	void reserve(int new_alloc);
	void resize(int new_size, T val = T());
	void push_back(T val);

	~vector();
};