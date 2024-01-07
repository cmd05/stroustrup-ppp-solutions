#pragma once

#include <cstdlib>

template<typename T>
class allocator {
public:
    T* allocate(int n);
    void construct(T* p, T val);
    void destroy(T* p);
    void deallocate(T* p, int space);
};

template<typename T>
T* allocator<T>::allocate(int n) {
    return (T*) malloc(n * sizeof(T)); // implicit conversion of void* to T*
}

template<typename T>
void allocator<T>::construct(T* p, T val) {
    // placement new
	// new (<address>) <type>(<initializer>)
	// (https://en.cppreference.com/w/cpp/language/new#Placement_new)
    new(p) T{val};
}

template<typename T>
void allocator<T>::destroy(T* p) {
	// explicit call to destructor
    p->~T();
}

template<typename T>
void allocator<T>::deallocate(T* p, int n) {
    free(p);
}