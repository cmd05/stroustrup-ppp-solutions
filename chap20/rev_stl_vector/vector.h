#pragma once

#include "vector_base.h"
#include "allocator.h"

#include <memory>
#include <initializer_list>
#include <algorithm>

/**
 * NOTES:
 * For type T, we assume any constructor or copy/move assignment of T may throw.
 * (https://isocpp.org/wiki/faq/exceptions#ctor-exceptions)
 * 
 * Allocators are stateless and need not be copied or moved
 * 
 * By convention, vector deals with typed memory (construct() and destroy()), while vector_base deals with raw memory (deallocate())
 * However, vector does use allocate()
 * 
 * All vector operations must provide atleast basic guarantee
*/  

template<typename T, typename A = allocator<T>>
class vector : private vector_base<T,A> {
private:
    void swap_vb_elems(vector_base<T,A>& vb); // idiomatically, elements of vector are changed
    void swap_vb_space(vector_base<T,A>& vb); // idiomatically, elements of vector are same, only space is changed
public:
    // typedefs
    using size_type = unsigned long;
    using value_type = T;
    using iterator = T*;
    using const_iterator = const T*;
    
    // Constructors
    vector() {}

    explicit vector(int s, T val = T());
    vector(std::initializer_list<T> lst);
    
    // Destructor
    ~vector();

    // Iterators
    iterator begin() const { return iterator{&this->elem[0]}; }
    iterator end() const { return iterator{&this->elem[this->sz]}; }

    // Copy Operations
    vector(const vector& vc);
    vector& operator=(const vector& vc);

    // Move operations
    vector(vector&& vc);
    vector& operator=(vector&& vc);

    // Access operations
    T& operator[](int n) { return this->elem[n]; }
    const T& operator[](int n) const { return this->elem[n]; }

    int size() const { return this->sz; }
    int capacity() const { return this->space; }

    // Modifiers
    void push_back(const T& val);
    iterator insert(iterator p, const T& val);

    void reserve(int s);
    void resize(int s, T val = T());
};

/// Private Methods

template<typename T, typename A>
void vector<T,A>::swap_vb_elems(vector_base<T,A>& vb) {
    // `size()` changes
    std::swap(this->sz, vb.sz);
    std::swap(this->space, vb.space);
    std::swap(this->elem, vb.elem);
}

template<typename T, typename A>
void vector<T,A>::swap_vb_space(vector_base<T,A>& vb) {
    // `size()` does not change
    std::swap(this->space, vb.space);
    std::swap(this->elem, vb.elem);
}

/// Public Methods

/// Constructors

template<typename T, typename A>
vector<T,A>::vector(std::initializer_list<T> lst) {
    this->space = this->sz = lst.size();
    this->elem = this->alloc.allocate(this->sz);

    std::uninitialized_copy(lst.begin(), lst.end(), this->elem);
}

template<typename T, typename A>
vector<T,A>::vector(int s, T val) {
    this->space = this->sz = s;
    this->elem = this->alloc.allocate(this->sz);

    for(int i = 0; i < size(); i++) this->alloc.construct(&this->elem[i], val);
}

/// Destructor
template<typename T, typename A>
vector<T,A>::~vector() {
    for(int i = 0; i < this->space; i++) this->alloc.destroy(&this->elem[i]);
    // vector_base deals deallocate
}

/// Copy Operations

template<typename T, typename A>
vector<T,A>::vector(const vector& vc) {
    this->space = this->sz = vc.sz;
    this->elem = this->alloc.allocate(this->sz);

    std::uninitialized_copy(vc.elem, vc.elem + vc.sz, this->elem);
}

template<typename T, typename A>
vector<T,A>& vector<T,A>::operator=(const vector& vc) {
    if(&vc == this) return *this;

    if(this->space < vc.sz) {
        vector_base<T,A> vb {this->alloc, vc.sz};
        std::uninitialized_copy(vc.elem, vc.elem + vc.sz, vb.elem);

        swap_vb_elems(vb);

        return *this;
    }

    std::copy(vc.elem, vc.elem + vc.sz, this->elem);
    this->sz = vc.sz;

    return *this;
}

/// Move Operations

template<typename T, typename A>
vector<T,A>::vector(vector&& vc) {
    this->elem = vc.elem;
    this->space = vc.space;
    this->sz = vc.sz;

    vc.elem = nullptr;
    vc.sz = vc.space = 0;
}

template<typename T, typename A>
vector<T,A>& vector<T,A>::operator=(vector&& vc) {
    if(&vc == this) return *this;

    // Since elem points to vc.elem after these operations, same memory is never freed twice
    for(int i = 0; i < this->space; i++) this->alloc.destroy(&this->elem[i]);
    this->deallocate_elem();

    this->elem = vc.elem;
    this->space = vc.space;
    this->sz = vc.sz;

    vc.elem = nullptr;
    vc.sz = vc.space = 0;

    return *this;
}

/// Modifiers

template<typename T, typename A>
void vector<T,A>::push_back(const T& val) {
    insert(end(), val);
}

template<typename T, typename A>
typename vector<T,A>::iterator vector<T,A>::insert(iterator p, const T& val) {
    size_type index = p - begin();

    if(this->space == 0) 
        reserve(8); 
    else if(this->sz == this->space)
        reserve(2*this->space);
    
    for(size_type i = this->sz; i > index; i--)
        this->elem[i] = this->elem[i-1];

    this->elem[index] = val;

    ++(this->sz);

    return iterator{&this->elem[index]};
}

template<typename T, typename A>
void vector<T,A>::reserve(int new_alloc) {
    if(new_alloc <= this->space) return;

    vector_base<T,A> vb {this->alloc, new_alloc};
    std::uninitialized_copy(this->elem, this->elem + size(), vb.elem); // copy old elements
    
    for(int i = 0; i < size(); i++)
        this->alloc.destroy(&this->elem[i]); // destroy old elements

    swap_vb_space(vb);
}

template<typename T, typename A>
void vector<T,A>::resize(int s, T val) {
    if(s < 0) return;
    reserve(s);

    for(int i = this->sz; i < s; i++)
        this->alloc.construct(&this->elem[i], val);

    this->sz = s;
}