#pragma once
#include "vector.h"
#include <memory>

struct Range_Error { int n; };

template<typename T, typename A = std::allocator<T>>
class strict_vector : public std::vector<T,A> {
    using vector<T>::vector; // use constructors of vector

    T& operator[](int n) { 
        if(i < 0 || i >= size()) throw Range_Error{n};
        return this->elem[n];
    }

    const T& operator[](int n) const {
        if(i < 0 || i >= size()) throw Range_Error{n};
        return this->elem[n];
    }
};