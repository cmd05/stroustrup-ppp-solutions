#pragma once
#include "vector.h"

template<typename T> 
struct Vector_Strict : public vector<T> {
	using size_type = typename std::vector<T>::size_type;
	using vector<T>::vector;

	T& operator[](size_type i);
	const T& operator[](size_type i);
};